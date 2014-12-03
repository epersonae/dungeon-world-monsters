<?php
/**
 * @file
 * dungeon_world_monster_compendium.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dungeon_world_monster_compendium_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'monsters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Monsters';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Monsters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_instinct' => 'field_instinct',
    'field_moves' => 'field_moves',
    'field_setting' => 'field_setting',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_instinct' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_moves' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_setting' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Instinct */
  $handler->display->display_options['fields']['field_instinct']['id'] = 'field_instinct';
  $handler->display->display_options['fields']['field_instinct']['table'] = 'field_data_field_instinct';
  $handler->display->display_options['fields']['field_instinct']['field'] = 'field_instinct';
  /* Field: Content: Moves */
  $handler->display->display_options['fields']['field_moves']['id'] = 'field_moves';
  $handler->display->display_options['fields']['field_moves']['table'] = 'field_data_field_moves';
  $handler->display->display_options['fields']['field_moves']['field'] = 'field_moves';
  $handler->display->display_options['fields']['field_moves']['delta_offset'] = '0';
  /* Field: Content: Setting */
  $handler->display->display_options['fields']['field_setting']['id'] = 'field_setting';
  $handler->display->display_options['fields']['field_setting']['table'] = 'field_data_field_setting';
  $handler->display->display_options['fields']['field_setting']['field'] = 'field_setting';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'monster' => 'monster',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'monsters';
  $export['monsters'] = $view;

  return $export;
}
