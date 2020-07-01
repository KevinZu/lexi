#include <stdio.h>
#include <gtk/gtk.h>
void gtest(int a)
{
	printf("===:%d\n",a);
}

int gt( int argc, char **argv)
{
    GtkWidget *window;
    /*初始化整个GTK+程序，是每一个GTK+程序必不可少的部分*/
    gtk_init(&argc, &argv);
    /*这里生成了一个窗口构件——GtkWindow，GTK_WINDOW_TOPLEVEL包含窗口的标题栏和边框，同意用窗口管理器来进行管理*/
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /*开始显示窗口*/
    gtk_widget_show(window);
    gtk_main();
    return 0;
}
