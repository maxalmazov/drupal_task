(function ($) {
    $(document).keydown(function(event) {
        if (event.ctrlKey && event.keyCode == 13) {
            $.fn.typos_report_window();
        }
    });

    $.fn.typos_report_window = function() {
        var sel = typos_get_sel_text();
        var context = typos_get_sel_context(sel);

        if ($(sel.element).closest('.orpho-field').length){
            if (typeof Drupal.settings.typos !== "undefined") {
                alert('You can send only '+Drupal.settings.typos.max_reports+' reports per day');
                return;
            }
            var max_chars = $(sel.element).closest('div').attr('typos_max_chars');
            if (sel.selected_text.length > max_chars) {
                alert(Drupal.t('No more than !max_chars characters can be selected when creating a typo report.', {'!max_chars': max_chars}))
            } else if (sel.selected_text.length == 0) {
            } else {
                var popup_text = $(sel.element).closest('div').attr('typos_popup_text');
                Drupal.CTools.Modal.show(Drupal.settings.TyposModal);
                $('#typos-modal-content').html('&nbsp;');
                $('#typos-report-content').appendTo('#typos-modal-content');

                $('#typos-context-div').html(context);
                $('#typos_popup_text').html(popup_text);

                $('#typos_context').val(context);
                $('#typos_url').val(window.location);
                $('#typos_entity_type').val($(sel.element).closest('div').attr('entity_type'));
                $('#bundle').val($(sel.element).closest('div').attr('bundle'));
                $('#typos_nid').val($(sel.element).closest('div').attr('nid'));
                $('#typos_label').val($(sel.element).closest('div').attr('label'));
                $('#typos_field_name').val($(sel.element).closest('div').attr('field_name'));
                $('#revision').val($(sel.element).closest('div').attr('revision'));


                // Close modal by Esc press.
                $(document).unbind('keydown', modalEventEscapeCloseHandler); //see ctools/js/modal.js
                $(document).keydown(modalEventEscapeCloseHandler = function(e) {
                    if (e.keyCode == 27) {
                        typos_restore_form();
                        modalContentClose();
                        $(document).unbind('keydown', modalEventEscapeCloseHandler);
                    }
                });

                // Close modal by clicking outside the window.
                $('#modalBackdrop').click(typos_click_close = function(e) {
                    typos_restore_form();
                    modalContentClose();
                    $('#modalBackdrop').unbind('click', typos_click_close);
                });

                // Close modal by "close" link click.
                $('#close').click(typos_close_click = function(e) {
                    e.preventDefault();
                    typos_restore_form();
                    modalContentClose();
                    $(document).unbind('click', typos_close_click);
                });
            }
        }
    };

    /**
     * Function restores typo report form if form was shown, but report was not sent.
     */
    function typos_restore_form() {
        if($('#typos-report-result').css('display') == 'none') {
            $('#typos-report-content').appendTo('#typos-report-wrapper');console.log('kirie eleison');
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

        context_start = selection_start - 40;
        if (context_start < 0) {
            context_start = 0;
        }

        context_end = selection_end + 40;
        if (context_end > context.length) {
            context_end = context.length;
        }

        context = context.substring(context_start, context_end);

        context_start = context.indexOf(' ') + 1;

        if (selection_start + 40 < context.length) {
            context_end = context.lastIndexOf(' ', selection_start + 40);
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

    // callback for Drupal ajax_command_invoke function
    $.fn.typos_js_callback = function(res) {
        $('#typos-report-message').css({'display': 'none'});
        $('#typos-report-result').css({'display': 'block'}).html(Drupal.t('Your message has been sent. Thank you.'));
        setTimeout(modalContentClose, 1000);
    };
})(jQuery);