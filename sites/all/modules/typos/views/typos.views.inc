<?php
/**
 * @file
 * Provide views data and handlers for typo.module
 */


/**
 * Implementation of hook_views_data()
 */
function typos_views_data() {
    // Basic table information.

    $data['typos']['table']['group']  = t('Typos Report');

    // Advertise this table as a possible base table
    $data['typos']['table']['base'] = [
        'field' => 'typo_id',
        'title' => t('Typo report'),
        'help' => t('Typo report messages.'),
    ];


    return $data;
}