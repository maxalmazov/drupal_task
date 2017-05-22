<?php
/**
 * @file
 * Default views for Typo module.
 */
function typos_views_default_views() {
    $view = new view();
    $view->name = 'typo_report';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'typos_report';
    $view->human_name = 'Typo report';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Typo report';
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'administer permissions';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['grouping'] = array(
        0 => array(
            'field' => 'created_at',
            'rendered' => 1,
            'rendered_strip' => 0,
        ),
    );
    $handler->display->display_options['style_options']['columns'] = array(
        'entity_type' => 'entity_type',
        'bundle' => 'bundle',
        'revision' => 'revision',
        'url' => 'url',
        'field_name' => 'field_name',
        'node_id' => 'node_id',
        'comment' => 'comment',
        'text' => 'text',
        'user_id' => 'user_id',
        'user_ip' => 'user_ip',
        'created_at' => 'created_at',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
        'entity_type' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'bundle' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'revision' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'url' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'field_name' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'entity_id' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'comment' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'text' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'user_id' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'user_ip' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'created_at' => array(
            'sortable' => 1,
            'default_sort_order' => 'desc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
    /* Field: Typos report: Entity type */
    $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
    $handler->display->display_options['fields']['entity_type']['table'] = 'typos_report';
    $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
    /* Field: Typos report: Bundle */
    $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
    $handler->display->display_options['fields']['bundle']['table'] = 'typos_report';
    $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
    /* Field: Typos report: revision */
    $handler->display->display_options['fields']['revision']['id'] = 'revision';
    $handler->display->display_options['fields']['revision']['table'] = 'typos_report';
    $handler->display->display_options['fields']['revision']['field'] = 'revision';
    /* Field: Typos report: Typo URL */
    $handler->display->display_options['fields']['url']['id'] = 'url';
    $handler->display->display_options['fields']['url']['table'] = 'typos_report';
    $handler->display->display_options['fields']['url']['field'] = 'url';
    /* Field: Typos report: Field name */
    $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
    $handler->display->display_options['fields']['field_name']['table'] = 'typos_report';
    $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
    /* Field: Typos report: Node ID */
    $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
    $handler->display->display_options['fields']['entity_id']['table'] = 'typos_report';
    $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
    /* Field: Typos report: Typo comment */
    $handler->display->display_options['fields']['comment']['id'] = 'comment';
    $handler->display->display_options['fields']['comment']['table'] = 'typos_report';
    $handler->display->display_options['fields']['comment']['field'] = 'comment';
    /* Field: Typos report: Typo text */
    $handler->display->display_options['fields']['text']['id'] = 'text';
    $handler->display->display_options['fields']['text']['table'] = 'typos_report';
    $handler->display->display_options['fields']['text']['field'] = 'text';
    /* Field: Typos report: User ID */
    $handler->display->display_options['fields']['user_id']['id'] = 'user_id';
    $handler->display->display_options['fields']['user_id']['table'] = 'typos_report';
    $handler->display->display_options['fields']['user_id']['field'] = 'user_id';
    /* Field: Typos report: User IP */
    $handler->display->display_options['fields']['user_ip']['id'] = 'user_ip';
    $handler->display->display_options['fields']['user_ip']['table'] = 'typos_report';
    $handler->display->display_options['fields']['user_ip']['field'] = 'user_ip';
    /* Field: Typos report: Date */
    $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
    $handler->display->display_options['fields']['created_at']['table'] = 'typos_report';
    $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
    $handler->display->display_options['fields']['created_at']['date_format'] = 'long';
    $handler->display->display_options['fields']['created_at']['second_date_format'] = 'long';
    /* Sort criterion: Typos report: Date */
    $handler->display->display_options['sorts']['created_at']['id'] = 'created_at';
    $handler->display->display_options['sorts']['created_at']['table'] = 'typos_report';
    $handler->display->display_options['sorts']['created_at']['field'] = 'created_at';
    $handler->display->display_options['sorts']['created_at']['order'] = 'DESC';

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'typo-report';


    return array('typos_report' => $view);
}
