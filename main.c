#include <gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *w = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(w), "HennnnaIro");
    gtk_window_set_default_size(GTK_WINDOW(w), 400, 300);

    // CSS で背景色を指定
    GtkCssProvider *css = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css,
        "window { background-color: #bada55; }", -1, NULL);
    GtkStyleContext *ctx = gtk_widget_get_style_context(w);
    gtk_style_context_add_provider(ctx,
        GTK_STYLE_PROVIDER(css),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_widget_show_all(w);
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new(
        "com.example.HennnnaIro", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate",
                     G_CALLBACK(activate), NULL);
    int status = g_application_run(
        G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

