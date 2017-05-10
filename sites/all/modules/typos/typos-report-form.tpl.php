<div id="typos-report-content">
    <div id="typos-report-message">
        <div id="typos-message">
            <?php
            print t('You are reporting a typo in the following text:');
            ?>
            <div id="typos-context-div"></div>
            <?php
            print t('Simply click the "Send typo report" button to complete the report. You can also include a comment.');
            ?>
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