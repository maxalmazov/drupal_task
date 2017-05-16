<?php
/**
 * @file
 * Default views for Typo module.
 */
function typos_views_default_views() {
  $view = new view;
  $view->name = 'typos_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'typos-report';
  $view->human_name = 'Typo reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */



  return array('typos_reports' => $view);
}
