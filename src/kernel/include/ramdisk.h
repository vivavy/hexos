/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 * 
 * This file contains the RAMDisk definitions.
 */

#pragma once

#include <types.hpp>

typedef uint Node;

extern void RAMDisk_Init(void);

extern uint RAMDisk_Create_Disk(void);

extern void RAMDisk_Create_Directory(in Node node, in char *name, in uint uid, in uint flags);

extern void RAMDisk_Create_File(in Node node, in char *name, in uint uid, in uint flags);

extern void RAMDisk_Chmod(in Node node, in uint new_flags);

extern void RAMDisk_Remove_Child(in Node node, in char *name);

extern void RAMDisk_Write(in Node node, in char *data, in uint size);

extern uint RAMDisk_Read(in Node node, out char *data, out uint size);

extern uint RAMDisk_Size(in Node node);

extern Bool RAMDisk_IsOwner(in Node node, in uint uid);

extern Bool RAMDisk_IsReadable(in Node node);

extern Bool RAMDisk_IsWritable(in Node node);

extern Bool RAMDisk_IsExecutable(in Node node);

extern Bool RAMDisk_IsDirectory(in Node node);

extern Node RAMDisk_GetChild(in Node node, in char *name);

extern Node RAMDisk_GetChildByPath(in Node node, in char *path);