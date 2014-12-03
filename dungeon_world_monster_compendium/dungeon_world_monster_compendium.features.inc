<?php
/**
 * @file
 * dungeon_world_monster_compendium.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dungeon_world_monster_compendium_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function dungeon_world_monster_compendium_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dungeon_world_monster_compendium_node_info() {
  $items = array(
    'monster' => array(
      'name' => t('Monster'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
