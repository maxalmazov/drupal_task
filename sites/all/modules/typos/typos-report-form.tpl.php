<div id="typos-report-content">
    <div id="typos-report-message">
        <div id="typos-message">
            <?php
            print t('You are reporting a typo in the following text:');
            ?>
            <div id="typos-context-div"></div>
            <div id="typos_popup_text"></div>
        </div>
        <div id="typos-form">
            <?php
            print $typos_report_form;
            ?>
        </div>
    </div>
    <div id="typos-report-result" style="display: none;">
    </div>
</div>
<div id="tmp"></div>