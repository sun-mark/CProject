//
// 0Created by Administrator on 2022/11/1 0001.
//
#include "gtk_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#define input_0 "0"
#define input_1 "1"
#define input_2 "2"
#define input_3 "3"
#define input_4 "4"
#define input_5 "5"
#define input_6 "6"
#define input_7 "7"
#define input_8 "8"
#define input_9 "9"
#define input_plus "+"
#define input_minus "-"
#define input_multiply "*"
#define input_divide "/"
#define input_equal "="
#define input_clear "C"
#define input_percent "%"
#define input_point "."


#define BIND_BUTTON(builder, input_value) \
 {GtkButton *button_input##input_value=(GtkButton *)gtk_builder_get_object(builder,"input_"input_##input_value) ; \
g_signal_connect(button_input##input_value,"clicked",G_CALLBACK(OnInputButtonClicked),input_##input_value);}
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
    if (gtk_builder_add_from_file(gtkBuilder, "../ui/calculator.xml", &gError) == 0) {
        g_printerr("Error loading ui xml file :%s\n", gError->message);
        g_clear_error(&gError);
        return;
    }
    GtkWindow *window = (GtkWindow *) gtk_builder_get_object(gtkBuilder, "window");
    gtk_style_context_add_provider_for_screen(gtk_window_get_screen(GTK_WINDOW(window)),
                                              (GtkStyleProvider *) gtkCssProvider,
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    ui_context->text_displayer = gtk_builder_get_object(gtkBuilder, "show_result");
    BIND_BUTTON(gtkBuilder, 0);
    BIND_BUTTON(gtkBuilder, 1);
    BIND_BUTTON(gtkBuilder, 2);
    BIND_BUTTON(gtkBuilder, 3);
    BIND_BUTTON(gtkBuilder, 4);
    BIND_BUTTON(gtkBuilder, 5);
    BIND_BUTTON(gtkBuilder, 6);
    BIND_BUTTON(gtkBuilder, 7);
    BIND_BUTTON(gtkBuilder, 8);
    BIND_BUTTON(gtkBuilder, 9);
    BIND_BUTTON(gtkBuilder, plus);
    BIND_BUTTON(gtkBuilder, minus);
    BIND_BUTTON(gtkBuilder, multiply);
    BIND_BUTTON(gtkBuilder, divide);
    BIND_BUTTON(gtkBuilder, equal);
    BIND_BUTTON(gtkBuilder, clear);
    BIND_BUTTON(gtkBuilder, percent);
    BIND_BUTTON(gtkBuilder, point);
    HandleInput(ui_context->context, '0');
    gtk_main();
    g_object_unref(gtkBuilder);
//    gtk_style_context_remove_provider_for_screen(gtk_window_get_screen(window), gtkCssProvider);
    g_object_unref(gtkCssProvider);
}

static void InitConsole(int argc, char *argv[]) {
    ui_context = malloc(sizeof(*ui_context));
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