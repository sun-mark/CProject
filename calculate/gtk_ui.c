//
// 0Created by Administrator on 2022/11/1 0001.
//
#include "gtk_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static UiContext *ui_context;

static void DisplayTextWithFileGTKLabel(char *text) {
    gtk_label_set_text(ui_context->text_displayer, text);


}

static void OnInputButtonClicked(void *widget, void *data) {
    HandleInput(ui_context->context, ((char *) data)[0]);
}

static void GTKMain(int argc, char *argv[]) {

    GError *gError = NULL;
    gtk_init(&argc, &argv);
    GtkCssProvider *gtkCssProvider = gtk_css_provider_new();
    if (gtk_css_provider_load_from_path(gtkCssProvider, "../ui/style.css", &gError) == 0) {
        g_printerr("Error loading css file :%s\n", gError->message);
        g_clear_error(&gError);
        return;
    }
    GtkBuilder *gtkBuilder = gtk_builder_new();
    if (gtk_builder_add_from_file(gtkBuilder, "E:\\CProject\\calculate\\ui\\calculator.xml", &gError) == 0) {
        g_printerr("Error loading ui xml file :%s\n", gError->message);
        g_clear_error(&gError);
        return;
    }
    GtkWindow *window = (GtkWindow *) gtk_builder_get_object(gtkBuilder, "window");
    gtk_style_context_add_provider_for_screen(gtk_window_get_screen(GTK_WINDOW(window)),
                                              (GtkStyleProvider *) gtkCssProvider,
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    ui_context->text_displayer = (GtkLabel *) gtk_builder_get_object(gtkBuilder, "result_show");
    GtkButton *button_input_0 = (GtkButton *) gtk_builder_get_object(gtkBuilder, "input_0");
    g_signal_connect(button_input_0, "clicked", G_CALLBACK(OnInputButtonClicked), "0");
    HandleInput(ui_context->context, '0');
    gtk_main();
    g_object_unref(gtkBuilder);
    gtk_style_context_remove_provider_for_screen(gtk_window_get_screen(window), (GtkStyleProvider *) gtkCssProvider);
    g_object_unref(gtkCssProvider);
}

static void InitConsole(int argc, char *argv[]) {
    ui_context = malloc(sizeof(&ui_context));
    ui_context->context = CreateCalcContext();
    ui_context->context->display_text = (void (*)(char *)) DisplayTextWithFileGTKLabel;
}

static void DestroyConsole() {
    DestroyCalcContext(&ui_context->context);
    free(ui_context);
    ui_context = NULL;
}

int RunGtkUi(int argc, char *argv[]) {
    InitConsole(argc, argv);
    GTKMain(argc, argv);
    DestroyConsole();
    return 0;
}