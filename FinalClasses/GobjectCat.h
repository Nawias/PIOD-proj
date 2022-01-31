#ifndef PROGRAMOWANIE_GOBJECTCAT_H
#define PROGRAMOWANIE_GOBJECTCAT_H
#include <glib-object.h>
#include <string>

G_BEGIN_DECLS

/* Type Declaration */
#define GOBJECT_TYPE_CAT (gobject_cat_get_type())
G_DECLARE_FINAL_TYPE(GobjectCat, gobject_cat,GOBJECT,CAT,GObject)

/* Method Declarations */
GobjectCat* gobject_cat_new(void);
void gobject_cat_meow(GobjectCat *self);
G_END_DECLS

#endif //PROGRAMOWANIE_GOBJECTCAT_H