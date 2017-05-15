(function ($) {
    $(document).keydown(function(event) {
        if (event.shiftKey && event.keyCode == 13) {
            $.fn.typos_report_window();
        }
    });

    $.fn.typos_report_window = function() {
        var sel = typos_get_sel_text();
        var context = typos_get_sel_context(sel);
        if ($(sel.element).closest('.orpho-field').length){
            var popup_text = $(sel.element).closest('div').attr('typos_popup_text');
            Drupal.CTools.Modal.show(Drupal.settings.TyposModal);
            $('#typos-modal-content').html('&nbsp;');
            $('#typos-report-content').appendTo('#typos-modal-content');

            $('#typos-context-div').html(context);
            $('#typos_popup_text').html(popup_text);
            $('#typos-context').val(context);
            $('#typos-url').val(window.location);


            // Close modal by Esc press.
            $(document).keydown(typos_close = function(e) {
                if (e.keyCode == 27) {
                    typos_restore_form();
                    modalContentClose();
                    $(document).unbind('keydown', typos_close);
                }
            });

            // Close modal by clicking outside the window.
            $('#modalBackdrop').click(typos_click_close = function(e) {
                typos_restore_form();
                modalContentClose();
                $('#modalBackdrop').unbind('click', typos_click_close);
            });

            // Close modal by "close" link click.
            $('#close').click(function(e) {
                typos_restore_form();
                modalContentClose();
                $(document).unbind('keydown', typos_close);
            });
        }

        console.log($(sel.element).closest('div'));
        console.log($(sel.element).closest('div').is('[typos_max_chars]'));
        console.log($(sel.element).closest('div').attr('typos_max_chars'));

    };

    /**
     * Function restores typo report form if form was shown, but report was not sent.
     */
    function typos_restore_form() {
        if($('#typos-report-result').css('display') == 'none') {
            $('#typos-report-content').appendTo('#typos-report-wrapper');
        }
    }

    /**
     * Function finds selected text.
     */
    function typos_get_sel_text() {
        if (window.getSelection) {
            txt = window.getSelection();
            selected_text = txt.toString();
            element = txt.anchorNode;
            full_text = txt.anchorNode.textContent;
            selection_start = txt.anchorOffset;
            selection_end = txt.focusOffset;
        } else {
            return;
        }

        var txt = {
            selected_text: selected_text,
            full_text: full_text,
            selection_start: selection_start,
            selection_end: selection_end,
            element: element
        };

        return txt;
    }

    /**
     * Function gets a context of selected text.
     */
    function typos_get_sel_context(sel) {
        selection_start = sel.selection_start;
        selection_end = sel.selection_end;
        if (selection_start > selection_end) {
            tmp = selection_start;
            selection_start = selection_end;
            selection_end = tmp;
        }

        context = sel.full_text;

        context_first = context.substring(0, selection_start);
        context_second = '<strong>' + context.substring(selection_start, selection_end) + '</strong>';
        context_third = context.substring(selection_end, context.length);
        context = context_first + context_second + context_third;

        context_start = selection_start - 60;
        if (context_start < 0) {
            context_start = 0;
        }

        context_end = selection_end + 60;
        if (context_end > context.length) {
            context_end = context.length;
        }

        context = context.substring(context_start, context_end);

        context_start = context.indexOf(' ') + 1;

        if (selection_start + 60 < context.length) {
            context_end = context.lastIndexOf(' ', selection_start + 60);
        }
        else {
            context_end = context.length;
        }

        selection_start = context.indexOf('<strong>');
        if (context_start > selection_start) {
            context_start = 0;
        }

        if (context_start) {
            context = context.substring(context_start, context_end);
        }

        return context;
    }

})(jQuery);