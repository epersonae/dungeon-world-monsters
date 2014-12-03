<?php
/**
 * @file
 * dungeon_world_monster_compendium.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function dungeon_world_monster_compendium_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'monster_tags-description-find_replace';
  $feeds_tamper->importer = 'monster_tags';
  $feeds_tamper->source = 'description';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ': ',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace colon';
  $export['monster_tags-description-find_replace'] = $feeds_tamper;

  return $export;
}
