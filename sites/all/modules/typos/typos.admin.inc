<?php
/**
 * @file
 * Admin settings form for vk_openapi module
 */

/**
 * Typo settings form.
 */
function typos_admin_settings() {
    global $base_url;

    $form['typos_reports_ttl'] = [
        '#type' => 'select',
        '#title' => t('Delete old typo reports'),
        '#description' => t('Delete typo reports older than N days'),
        '#default_value' => variable_get('typo_reports_ttl', 4320),
        '#options' => [
            1440 => t('1 day'),
            4320 => t('3 days'),
            10080 => t('1 week'),
            0 => t('Never'),
        ],
    ];

    $form['typos_reports_email'] = [
        '#type' => 'textfield',
        '#title' => t('Email to send report'),
        '#default_value' => !empty(variable_get('typos_reports_email')) ? variable_get('typos_reports_email') : variable_get('site_mail'),
    ];

    $form['typos_max_chars'] = array(
        '#type' => 'textfield',
        '#title' => t('Maximum characters in selection'),
        '#default_value' => variable_get('typos_max_chars', 10),
    );

    $form['typos_max_reports'] = array(
        '#type' => 'textfield',
        '#title' => t('Maximum reports in one day'),
        '#description' => '"0" - unlimited',
        '#default_value' => variable_get('typos_max_reports', 3),
    );

    return system_settings_form($form);
}

/**
 * Typo settings form validator.
 */
function typos_admin_settings_validate($form, &$form_state) {
    if(!is_numeric($form_state['values']['typos_max_chars']) || $form_state['values']['typos_max_chars'] < 0) {
        form_set_error('typos_max_chars', t('Maximum characters in selection should be an integer.'));
    }
    else {
        $form_state['values']['typos_max_chars'] = (int) $form_state['values']['typos_max_chars'];
    }

    if(!is_numeric($form_state['values']['typos_max_reports']) || $form_state['values']['typos_max_reports'] < 0) {
        form_set_error('typos_max_reports', t('Maximum reports in the day must be an integer.'));
    }
    else {
        $form_state['values']['typos_max_reports'] = (int) $form_state['values']['typos_max_reports'];
    }

    if (!valid_email_address($form_state['values']['typos_reports_email'])) {
        form_set_error('typos_reports_email', 'Your email address is not valid');
    }
}
