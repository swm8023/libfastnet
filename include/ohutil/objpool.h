#ifndef OHUTIL_OBJPOOL_H
#define OHUTIL_OBJPOOL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <ohutil/container.h>

#define OBJPOOL_OBJ_BASE(tpobj)     \
    SPLST_DEFNEXT(tpobj)


#define OBJPOOL_BASE(tpobj)         \
    tpobj *free_elem;               \
    objpool_blk *blks;              \
    int objsize;                    \
    int blksize;                    \
    int blkcnt;



typedef struct _tag_objpool_obj_base {
    OBJPOOL_OBJ_BASE(struct _tag_objpool_obj_base);
} objpool_obj_base;

typedef struct _tag_objpool_blk {
    void *data;
    SPLST_DEFNEXT(struct _tag_objpool_blk);
} objpool_blk;

typedef struct _tag_objpool_base {
    OBJPOOL_BASE(objpool_obj_base);
} objpool_base;

void objpool_init(objpool_base*, int, int);
void objpool_destroy(objpool_base*);
objpool_obj_base *objpool_get_obj(objpool_base*);
objpool_obj_base *objpool_free_obj(objpool_base*,  void *elem);



#ifdef __cplusplus
}
#endif

#endif // OHUTIL_OBJPOOL_H