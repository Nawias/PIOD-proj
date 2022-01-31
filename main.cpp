#include <iostream>
#include "FinalClasses/GobjectCat.h"
int main() {
    //default cat
    GobjectCat *gobjectCat = gobject_cat_new();
    gobject_cat_meow(gobjectCat);

    //cat with a different name
    GobjectCat *gobjectCat1 = gobject_cat_new();
    g_object_set(gobjectCat1,
                 "name","Rumba",
                 NULL);
    gobject_cat_meow(gobjectCat1);

    gchar *catName, *cat1Name;

    g_object_get(gobjectCat,
                 "name", &catName,
                 NULL);

    g_object_get(gobjectCat1,
                 "name", &cat1Name,
                 NULL);

    printf("%s and %s are cats\n", catName, cat1Name);

    g_free(catName);
    g_free(cat1Name);

    return 0;
}
