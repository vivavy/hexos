#include <types.hpp>

#define NODE_DIR 1ULL << 0
#define NODE_R 1ULL << 1
#define NODE_W 1ULL << 2
#define NODE_X 1ULL << 3
#define NODE_RW (NODE_R | NODE_W)
#define NODE_RX (NODE_R | NODE_X)
#define NODE_WX (NODE_W | NODE_X)
#define NODE_RWX (NODE_R | NODE_W | NODE_X)
#define NODE_RIGHTS_OWNER 0
#define NODE_RIGHTS_GROUP 3
#define NODE_RIGHTS_OTHER 6

uint node_dir = NODE_DIR;
uint node_r = NODE_R;
uint node_w = NODE_W;
uint node_x = NODE_X;
uint node_rw = NODE_RW;
uint node_rx = NODE_RX;
uint node_wx = NODE_WX;
uint node_rwx = NODE_RWX;
uint node_dir_needed = NODE_DIR                     |
                       NODE_X << NODE_RIGHTS_GROUP  |
                       NODE_X << NODE_RIGHTS_OTHER  |
                       NODE_RWX << NODE_RIGHTS_OWNER;
uint node_rights_owner = NODE_RIGHTS_OWNER;
uint node_rights_group = NODE_RIGHTS_GROUP;
uint node_rights_other = NODE_RIGHTS_OTHER;

extern void *kalloc(in uint);

void memcpy(in char *src, out char *dst, in uint size) {
    for (uint i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

template<typename T>
T *malloc(in uint size) {
    return (T *)kalloc(size);
}

class Chunk {
    public:
        Chunk(): prev((Chunk *)0), next((Chunk *)0), data((char *)0), size(0) {};
        Chunk(char *data, uint size): prev((Chunk *)0), next((Chunk *)0), data(data), size(size) {};
        Chunk(Chunk *prev, Chunk *next, char *data, uint size):
        prev(prev), next(next), data(data), size(size) {};
        void collect(out char **data, out uint *size) {
            uint raw_size = this->collectSize();
            char *raw_data = malloc<char>(raw_size);
            memcpy(raw_data, *data, raw_size);
            *size = raw_size;
        }
        uint collectSize() {
            if (this->next != (Chunk *)0) {
                return this->next->collectSize() + this->size;
            }
            return this->size;
        }
        ~Chunk() {
            if (this->next != (Chunk *)0) {
                delete this->next;
            }
            delete this->data;
        }
        Chunk *prev;
        Chunk *next;
        char *data;
        uint size;
};

uint strlen(in char *data) {
    uint i = 0;
    while (data[i] != '\0') {
        i++;
    }
    return i;
}

uint strlen(in char *data, in char separator) {
    uint i = 0;
    while (data[i] != separator) {
        i++;
    }
    return i;
}

uint strcmp(in char *data1, in char *data2) {
    uint i = 0;
    while (data1[i] != '\0' && data2[i] != '\0') {
        if (data1[i] != data2[i]) {
            return -1;
        }
        i++;
    }
    if (data1[i] == '\0' && data2[i] != '\0') {
        return -1;
    }
    if (data1[i] != '\0' && data2[i] == '\0') {
        return 1;
    }
    return 0;
}

uint strcmp(in char *data1, in const char *data2) {
    uint i = 0;
    while (data1[i] != '\0' && data2[i] != '\0') {
        if (data1[i] != data2[i]) {
            return -1;
        }
        i++;
    }
    if (data1[i] == '\0' && data2[i] != '\0') {
        return -1;
    }
    if (data1[i] != '\0' && data2[i] == '\0') {
        return 1;
    }
    return 0;
}

void split(in char *data, in uint size, out Chunk **first) {
    Chunk *chunk;
    *first = chunk;
    Chunk *temp_chunk;
    uint i = 0;
    uint temp_size = 0;
    while (i < size) {
        temp_size = strlen(data);
        temp_chunk = new Chunk(data, temp_size);
        chunk->next = temp_chunk;
        chunk = temp_chunk;
        data += temp_size + 1;
        i += temp_size + 1;
    }
}

void split(in char *data, in char separator, out Chunk **first) {
    Chunk *chunk;
    *first = chunk;
    Chunk *temp_chunk;
    uint i = 0;
    uint size = 0;
    while (data[i] != '\0') {
        size = strlen(data, separator);
        if (!size) continue;
        temp_chunk = new Chunk(data, size);
        chunk->next = temp_chunk;
        chunk = temp_chunk;
        data += size + 1;
        i += size + 1;
    }
}

class Node {
    public:
        Node *next;
        Chunk *first;
        uint flags;
        uint owner_id;
        const char *name;
    
        Node() {
            next = (Node *)0;
            first = (Chunk *)0;
            flags = 0;
            owner_id = 0;
        }
        Node(Node *next, Chunk *first, uint flags, uint owner_id, const char *name):
        next(next), first(first), flags(flags), owner_id(owner_id), name(name) {};

        Chunk *GetChildrenList() {
            char *data;
            uint size;
            first->collect(&data, &size);
            Chunk *first;
            split(data, size, &first);
            return first;
        }

        Node *GetChild(char *name) {
            Node *rvalue = (Node *)0;
            Chunk *list = this->GetChildrenList();
            for (; list->next != (Chunk *)0; list = list->next) {
                if (strcmp(list->data, name) == 0) {
                    rvalue = new Node(this->next, list->next, this->flags, this->owner_id, name);
                    break;
                }
            }
            return rvalue;
        }

        Node *GetChildByList(Chunk *list) {
            Node *rvalue = (Node *)0;
            for (; list->next != (Chunk *)0; list = list->next) {
                if (strcmp(list->data, name) == 0) {
                    rvalue = new Node(this->next, list->next, this->flags, this->owner_id, name);
                    break;
                }
            }
            return rvalue;
        }

        Node *GetChildByPath(char *path) {
            Node *rvalue = (Node *)0;
            Chunk *first;
            split(path, '/', &first);
            return this->GetChildByList(first);
        }

        void CreateChild(char *name, uint flags, uint owner_id) {
            Node *child = new Node(this->next, (Chunk *)0, flags, owner_id, name);
            this->next = child;
        }

        void RemoveChild(char *name) {
            Node *child = this->GetChild(name);
            if (child != (Node *)0) {
                this->next = child->next;
                delete child;
            }
        }

        bool IsDirectory() {
            return this->flags & NODE_DIR;
        }

        bool IsReadable() {
            return this->flags & NODE_R;
        }

        bool IsWritable() {
            return this->flags & NODE_W;
        }

        bool IsExecutable() {
            return this->flags & NODE_X;
        }

        bool IsOwner(uint uid) {
            return this->owner_id == uid;
        }
};

nomangle
void RAMDisk_Init(void) {}

nomangle
Node *RAMDisk_Create_Disk(void) {
    Node *root = new Node((Node *)0, (Chunk *)0, node_dir, 0, "/");
    return root;
}

nomangle
void RAMDisk_Create_Directory(in Node *node, in char *name, in uint uid, in uint flags) {
    node->CreateChild(name, node_dir_needed | flags, uid);
}

nomangle
void RAMDisk_Create_File(in Node *node, in char *name, in uint uid, in uint flags) {
    node->CreateChild(name, flags, uid);
}

nomangle
void RAMDisk_Chmod(in Node *node, in uint new_flags) {
    if (node->IsDirectory()) {
        node->flags = node_dir_needed | new_flags;
    } else {
        node->flags = new_flags;
    }
}

nomangle
void RAMDisk_Remove_Child(in Node *node, in char *name) {
    node->RemoveChild(name);
}

nomangle
void RAMDisk_Write(in Node *node, in char *data, in uint size) {
    if (node->IsDirectory()) {
        return;
    }
    Chunk *chunk = new Chunk(data, size);
    node->first = chunk;
}

nomangle
uint RAMDisk_Read(in Node *node, out char *data, out uint size) {
    if (node->IsDirectory()) {
        return 0;
    }
    node->first->collect(&data, &size);
    return size;
}

nomangle
uint RAMDisk_Size(in Node *node) {
    if (node->IsDirectory()) {
        return 0;
    }
    return node->first->collectSize();
}

nomangle
bool RAMDisk_IsOwner(in Node *node, in uint uid) {
    return node->IsOwner(uid);
}

nomangle
bool RAMDisk_IsReadable(in Node *node) {
    return node->IsReadable();
}

nomangle
bool RAMDisk_IsWritable(in Node *node) {
    return node->IsWritable();
}

nomangle
bool RAMDisk_IsExecutable(in Node *node) {
    return node->IsExecutable();
}

nomangle
bool RAMDisk_IsDirectory(in Node *node) {
    return node->IsDirectory();
}

nomangle
Node *RAMDisk_GetChild(in Node *node, in char *name) {
    return node->GetChild(name);
}

nomangle
Node *RAMDisk_GetChildByPath(in Node *node, in char *path) {
    return node->GetChildByPath(path);
}
