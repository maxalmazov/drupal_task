(function ($) {
    $(document).keydown(function(event) {
        if (event.shiftKey && event.keyCode == 13) {
            $.fn.typo_report();
            alert('l');
        }
    });

    $.fn.typo_report = function () {
        Drupal.CTools.Modal.show();
        $('#modal-title').html('title');
        $('#modal-content').html('content')

    };
})(jQuery);