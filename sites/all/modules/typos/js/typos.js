(function ($) {
    Drupal.behaviors.typosReport = {
        attach: function (context, setting) {
            $(context).keydown(function(event) {
                if (event.ctrlKey && event.keyCode == 13) {
                    $.fn.typos_report_window();
                }
            });
        }
    };

    $.fn.typos_report_window = function() {
        var sel = typos_get_sel_text();
        var contextTypo = typos_get_sel_context(sel);

        if ($(sel.element).closest('.orpho-field').length){
            if (typeof Drupal.settings.typos !== "undefined") {
                alert('You can send only '+Drupal.settings.typos.max_reports+' reports per day');
                return;
            }
            var maxChars = $(sel.element).closest('div').attr('typos_max_chars');
            if (sel.selectedText.length > maxChars) {
                alert(Drupal.t('No more than !maxChars characters can be selected when creating a typo report.', {'!maxChars': maxChars}))
            } else if (sel.selectedText.length == 0) {
            } else {
                var popupText = $(sel.element).closest('div').attr('typos_popup_text');
                Drupal.CTools.Modal.show(Drupal.settings.TyposModal);
                $('#typos-modal-content').html('&nbsp;');
                $('#typos-report-content').appendTo('#typos-modal-content');

                $('#typos-context-div').html(contextTypo);
                $('#typos_popup_text').html(popupText);

                $('#typos_context').val(contextTypo);
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
            $('#typos-report-content').appendTo('#typos-report-wrapper');
        }
    }

    /**
     * Function finds selected text.
     */
    function typos_get_sel_text() {
        if (window.getSelection) {
            txt = window.getSelection();
            selectedText = txt.toString();
            element = txt.anchorNode;
            fullText = txt.anchorNode.textContent;
            selectionStart = txt.anchorOffset;
            selectionEnd = txt.focusOffset;
        } else {
            return;
        }

        var txt = {
            selectedText: selectedText,
            fullText: fullText,
            selectionStart: selectionStart,
            selectionEnd: selectionEnd,
            element: element
        };

        return txt;
    }

    /**
     * Function gets a context of selected text.
     */
    function typos_get_sel_context(sel) {
        selectionStart = sel.selectionStart;
        selectionEnd = sel.selectionEnd;
        if (selectionStart > selectionEnd) {
            tmp = selectionStart;
            selectionStart = selectionEnd;
            selectionEnd = tmp;
        }

        contextTypo = sel.fullText;

        contextFirst = contextTypo.substring(0, selectionStart);
        contextSecond = '<strong>' + contextTypo.substring(selectionStart, selectionEnd) + '</strong>';
        contextThird = contextTypo.substring(selectionEnd, contextTypo.length);
        contextTypo = contextFirst + contextSecond + contextThird;

        contextStart = selectionStart - 40;
        if (contextStart < 0) {
            contextStart = 0;
        }

        contextEnd = selectionEnd + 40;
        if (contextEnd > contextTypo.length) {
            contextEnd = contextTypo.length;
        }

        contextTypo = contextTypo.substring(contextStart, contextEnd);

        contextStart = contextTypo.indexOf(' ') + 1;

        if (selectionStart + 40 < contextTypo.length) {
            contextEnd = contextTypo.lastIndexOf(' ', selectionStart + 40);
        }
        else {
            contextEnd = contextTypo.length;
        }

        selectionStart = contextTypo.indexOf('<strong>');
        if (contextStart > selectionStart) {
            contextStart = 0;
        }

        if (contextStart) {
            contextTypo = contextTypo.substring(contextStart, contextEnd);
        }

        return contextTypo;
    }

    // callback for Drupal ajax_command_invoke function
    $.fn.typos_js_callback = function(res) {
        $('#typos-report-message').css({'display': 'none'});
        $('#typos-report-result').css({'display': 'block'}).html(Drupal.t('Your message has been sent. Thank you.'));
        setTimeout(modalContentClose, 1000);
    };
})(jQuery);