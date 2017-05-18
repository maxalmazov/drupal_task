<?php
/**
 * @file
 * Provide views data and handlers for typo.module
 */


/**
 * Implementation of hook_views_data()
 */
function typos_views_data() {
    $data['typos_report']['table']['group']  = t('Typos report');

    $data['typos_report']['table']['base'] = [
        'field' => 'typo_id',
        'title' => t('Typos report'),
        'help' => t('Typos report messages.'),
    ];

    $data['typos_report']['entity_type'] = [
        'title' => t('Entity type'),
        'help' => t('Entity type where typo found.'),
        'field' => [
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    $data['typos_report']['url'] = [
        'title' => t('Typo URL'),
        'help' => t('URL where typo found.'),
        'field' => [
            'handler' => 'views_handler_field_url',
            'click sortable' => TRUE,
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    $data['typos_report']['text'] = [
        'title' => t('Typo text'),
        'help' => t('Context where typo found.'),
        'field' => [
            'handler' => 'views_handler_field_markup',
            'click sortable' => TRUE,
            'format' => filter_default_format(),
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    $data['typos_report']['comment'] = [
        'title' => t('Typo comment'),
        'help' => t('Comment from user about typo'),
        'field' => [
            'handler' => 'views_handler_field',
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    $data['typos_report']['createdAt'] = [
        'title' => t('Date'),
        'help' => t('Date report'),
        'field' => [
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
        ],
        'filter' => [
            'handler' => 'views_handler_filter_date',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_date',
        ],
    ];

    $data['typos_report']['node_id'] = [
        'title' => t('Node ID'),
        'help' => t('Node ID with typo'),
        'field' => [
            'handler' => 'views_handler_field',
        ],
        'filter' => [
            'handler' => 'views_handler_filter_numeric',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_numeric',
        ],
    ];

    $data['typos_report']['field_name'] = [
        'title' => t('Field name'),
        'help' => t('Field name where typo found'),
        'field' => [
            'handler' => 'views_handler_field',
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    $data['typos_report']['user_id'] = [
        'title' => t('User ID'),
        'help' => t('User ID reported'),
        'field' => [
            'handler' => 'views_handler_field',
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    $data['typos_report']['user_ip'] = [
        'title' => t('User IP'),
        'help' => t('User IP'),
        'field' => [
            'handler' => 'views_handler_field',
        ],
        'filter' => [
            'handler' => 'views_handler_filter_string',
        ],
        'sort' => [
            'handler' => 'views_handler_sort',
        ],
        'argument' => [
            'handler' => 'views_handler_argument_string',
        ],
    ];

    return $data;
}