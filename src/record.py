import common
import save

class Bitstream:
    int n
    char *b
    int acc
    int bit
    
def bitstream_add_bit(Bitstream *self, int x):
    self.acc += x << self.bit
    self.bit++
    if self.bit == 8:
        self.b = land_realloc(self.b, self.n + 1)
        self.b[self.n] = self.acc
        self.n++
        self.bit = 0
        self.acc = 0

def bitstream_get_bit(Bitstream *self, int t) -> int:
    int n = t >> 3
    int bit = t & 7
    return (self.b[n] >> bit) & 1

def bitstream_finish(Bitstream *self):
    while self.bit != 0:
        bitstream_add_bit(self, 0)
        
class Record:
    Bitstream inputs[5]
    bool is_recording
    bool is_replaying
    bool wait_on_level
    int tick

    int level
    int x, y, z

def record_new -> Record*:
    Record *r; land_alloc(r)
    return r

def record_destroy(Record *self):
    for int i in range(5):
        land_free(self.inputs[i].b)
    land_free(self)
    
static def recording_tick(Record *self):
    All *a = global_a
    bool controls[5] = {a.left, a.right, a.up, a.down, a.jump}
    
    for int i in range(5):
        bitstream_add_bit(&self.inputs[i], controls[i] ? 1 : 0)

static def replaying_tick(Record *self):
    All *a = global_a
    bool *controls[5] = {&a.left, &a.right, &a.up, &a.down, &a.jump}
    for int i in range(5):
        int bit = bitstream_get_bit(&self.inputs[i], self.tick)
        *(controls[i]) = bit
    self.tick++
    if self.tick >= self.inputs[0].n * 8:
        self.is_replaying = False

def record_tick(Record *self):
    if self.wait_on_level:
        return
    if self.is_recording:
        recording_tick(self)
    if self.is_replaying:
        replaying_tick(self)

def record_start(Record *self, int level, x, y, z):
    if not self.is_recording:
        return

    self.x = x
    self.y = y
    self.z = z
    self.level = level
    char name[1024]
    record_get_name(self, name)
    print("recording start %s", name)
    self.wait_on_level = False

def record_done(Record *self):
    if self.is_replaying:
        replay_done(self)
    if not self.is_recording:
        return
    if self.wait_on_level:
        return
    self.is_recording = False
    for int i in range(5):
        bitstream_finish(&self.inputs[i])
    char name[1024]
    record_get_name(self, name)
    LandBuffer *b = land_buffer_new()
    land_buffer_add_uint32_t(b, self.inputs[0].n)
    for int i in range(5):
        land_buffer_add(b, self.inputs[i].b, self.inputs[i].n)
    land_buffer_compress(b)
    land_buffer_write_to_file(b, name)
    land_buffer_destroy(b)
    record_clear(self)
    print("record_done %s", name)

def record_clear(Record *self):
    for int i in range(5):
        self.inputs[i].n = 0
        self.inputs[i].acc = 0
        self.inputs[i].bit = 0

def record_set_recording(Record *self):
    print("record_set_recording")
    self.is_replaying = False
    self.is_recording = True
    self.wait_on_level = True
    record_clear(self)

def record_set_replaying(Record *self):
    print("record_set_replaying")
    self.is_replaying = True
    self.is_recording = False
    self.wait_on_level = True
    record_clear(self)

static def record_get_name(Record *self, char *out):
    char suffix[1024]
    sprintf(suffix, "_%04d%04d%04d.gz", self.x + 22 * 24,
        self.y + 4 * 24, self.z + 22 * 24)
    save_get_name("record", self.level, suffix, out)

def replay_done(Record *self):
    if not self.is_replaying:
        return
    if self.wait_on_level:
        return
    self.is_replaying = False

def record_load(Record *self, int level, x, y, z):
    if self.is_recording:
        record_start(self, level, x, y, z)
    if self.is_replaying:
        replay_start(self, level, x, y, z)

def replay_start(Record *self, int level, x, y, z):
    if not self.is_replaying:
        return
    char name[1024]
    self.x = x
    self.y = y
    self.z = z
    self.level = level
    record_get_name(self, name)
    LandBuffer *b = land_buffer_read_from_file(name)
    if not b:
        print("could not replay %s", name)
        return
    land_buffer_decompress(b)
    int n = land_buffer_get_uint32_t(b, 0)
    for int i in range(5):
        Bitstream *bs = self.inputs + i
        bs.b = land_realloc(bs.b, n)
        bs.n = n
        memcpy(bs.b, b.buffer + 4 + i * n, n)
    land_buffer_destroy(b)
    self.tick = 0
    print("record_load %s (%d ticks)", name, n * 8)
    self.wait_on_level = False

    
