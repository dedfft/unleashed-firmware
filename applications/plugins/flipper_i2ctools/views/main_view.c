#include "main_view.h"

void draw_main_view(Canvas* canvas, i2cMainView* main_view) {
    canvas_clear(canvas);
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_rframe(canvas, 0, 0, 128, 64, 3);
    canvas_draw_icon(canvas, 2, 13, &I_passport_bad3_46x49);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str_aligned(canvas, 3, 3, AlignLeft, AlignTop, APP_NAME);

    switch(main_view->menu_index) {
    case SCAN_VIEW:
        canvas_set_color(canvas, ColorBlack);
        canvas_draw_str_aligned(
            canvas, SNIFF_MENU_X, SNIFF_MENU_Y, AlignLeft, AlignTop, SNIFF_MENU_TEXT);
        canvas_draw_str_aligned(
            canvas, SEND_MENU_X, SEND_MENU_Y, AlignLeft, AlignTop, SEND_MENU_TEXT);
        canvas_draw_rbox(canvas, 60, SCAN_MENU_Y - 2, 60, 13, 3);
        canvas_set_color(canvas, ColorWhite);
        canvas_draw_str_aligned(
            canvas, SCAN_MENU_X, SCAN_MENU_Y, AlignLeft, AlignTop, SCAN_MENU_TEXT);
        break;

    case SNIFF_VIEW:
        canvas_set_color(canvas, ColorBlack);
        canvas_draw_str_aligned(
            canvas, SCAN_MENU_X, SCAN_MENU_Y, AlignLeft, AlignTop, SCAN_MENU_TEXT);
        canvas_draw_str_aligned(
            canvas, SEND_MENU_X, SEND_MENU_Y, AlignLeft, AlignTop, SEND_MENU_TEXT);
        canvas_draw_rbox(canvas, 60, SNIFF_MENU_Y - 2, 60, 13, 3);
        canvas_set_color(canvas, ColorWhite);
        canvas_draw_str_aligned(
            canvas, SNIFF_MENU_X, SNIFF_MENU_Y, AlignLeft, AlignTop, SNIFF_MENU_TEXT);
        break;

    case SEND_VIEW:
        canvas_set_color(canvas, ColorBlack);
        canvas_draw_str_aligned(
            canvas, SCAN_MENU_X, SCAN_MENU_Y, AlignLeft, AlignTop, SCAN_MENU_TEXT);
        canvas_draw_str_aligned(
            canvas, SNIFF_MENU_X, SNIFF_MENU_Y, AlignLeft, AlignTop, SNIFF_MENU_TEXT);
        canvas_draw_rbox(canvas, 60, SEND_MENU_Y - 2, 60, 13, 3);
        canvas_set_color(canvas, ColorWhite);
        canvas_draw_str_aligned(
            canvas, SEND_MENU_X, SEND_MENU_Y, AlignLeft, AlignTop, SEND_MENU_TEXT);
        break;

    default:
        break;
    }
}

i2cMainView* i2c_main_view_alloc() {
    i2cMainView* main_view = malloc(sizeof(i2cMainView));
    main_view->menu_index = SCAN_VIEW;
    main_view->current_view = MAIN_VIEW;
    return main_view;
}

void i2c_main_view_free(i2cMainView* main_view) {
    furi_assert(main_view);
    free(main_view);
}