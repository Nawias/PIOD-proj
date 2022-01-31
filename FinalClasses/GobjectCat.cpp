#include "GobjectCat.h"

/* Destructor declaration */
static void gobject_cat_dispose (GObject *object);
static void gobject_cat_finalize (GObject *object);

/* Class Definition */
struct _GobjectCat
{
    GObject parent_instance;
    gchar* name;
};

G_DEFINE_TYPE(GobjectCat, gobject_cat,G_TYPE_OBJECT);

/* Properties */
enum
{
    PROP_NAME = 1,
    N_PROPERTIES
};
static GParamSpec *properties[N_PROPERTIES];

/* Property setter/getter definitions */

static void
gobject_cat_set_property (GObject *object,
                          guint propertyId,
                          const GValue *value,
                          GParamSpec *paramSpec)
{
    GobjectCat *self = GOBJECT_CAT(object);

    switch (propertyId) {
        case PROP_NAME:
            self->name = g_value_dup_string(value);
            g_object_notify_by_pspec(G_OBJECT(self), properties[PROP_NAME]);
            break;

        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object,propertyId,paramSpec);
            break;
    }
}

static void
gobject_cat_get_property (GObject *object,
                          guint propertyId,
                          GValue *value,
                          GParamSpec *paramSpec)
{
    GobjectCat *self = GOBJECT_CAT(object);

    switch (propertyId) {
        case PROP_NAME:
            g_value_set_string(value,self->name);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object,propertyId,paramSpec);
            break;
    }
}

/* Method Definitions */

/* Initialization - runs only the first time the class is used
 * NOT on every object instantiation
 */
static void
gobject_cat_class_init (GobjectCatClass *klass)
{
    GObjectClass *objectClass = G_OBJECT_CLASS(klass);
    GParamFlags default_flags = static_cast<GParamFlags>(G_PARAM_READWRITE | G_PARAM_CONSTRUCT | G_PARAM_STATIC_STRINGS |
                                                         G_PARAM_EXPLICIT_NOTIFY);

    objectClass->dispose = gobject_cat_dispose;
    objectClass->finalize = gobject_cat_finalize;
    objectClass->set_property = gobject_cat_set_property;
    objectClass->get_property = gobject_cat_get_property;

    properties[PROP_NAME] = g_param_spec_string("name",
                                                "Cat's name",
                                                "A name for the cat",
                                                "Mr. Speckles",
                                                default_flags);
    g_object_class_install_properties(objectClass, N_PROPERTIES, properties);
}

static void
gobject_cat_init (GobjectCat *self)
{
}

/* Destructor Declaration */
static void
gobject_cat_dispose(GObject *object)
{
    G_OBJECT_CLASS(gobject_cat_parent_class)->dispose(object);
}

static void
gobject_cat_finalize(GObject *object)
{
    GobjectCat *self = static_cast<GobjectCat *>(gobject_cat_get_instance_private(GOBJECT_CAT(object)));
    g_free ((gpointer) self->name);
    G_OBJECT_CLASS(gobject_cat_parent_class)->finalize(object);
}

/* Public Methods */

/* Constructor Definition */
GobjectCat *
gobject_cat_new (void){
    return (GobjectCat*)(g_object_new (GOBJECT_TYPE_CAT, NULL));
}

GobjectCat *
gobject_cat_new_with_name (const gchar *name){
    return (GobjectCat*)(g_object_new (GOBJECT_TYPE_CAT, "name",name));
}

void
gobject_cat_meow(GobjectCat *self) {
    printf("Meow, I am %s\n", self->name);
}