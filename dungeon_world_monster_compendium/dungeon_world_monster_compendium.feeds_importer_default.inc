<?php
/**
 * @file
 * dungeon_world_monster_compendium.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function dungeon_world_monster_compendium_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'monster_tags';
  $feeds_importer->config = array(
    'name' => 'Monster Tags',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'context' => array(
          'value' => 'mtags/p',
        ),
        'sources' => array(
          'name' => array(
            'name' => 'name',
            'value' => 'em',
            'raw' => 0,
            'debug' => 1,
            'weight' => '1',
          ),
          'description' => array(
            'name' => 'description',
            'value' => 'text()',
            'raw' => 0,
            'debug' => 1,
            'weight' => '2',
          ),
        ),
        'display_errors' => 1,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'use_tidy' => FALSE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'monster_tags',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['monster_tags'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'monsters';
  $feeds_importer->config = array(
    'name' => 'Monsters',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'use_tidy' => FALSE,
        'sources' => array(
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'raw' => 0,
            'debug' => 1,
            'weight' => '1',
          ),
          'monster_tags' => array(
            'name' => 'monster tags',
            'value' => 'tags/tag',
            'raw' => 0,
            'debug' => 1,
            'weight' => '2',
          ),
          'setting' => array(
            'name' => 'setting',
            'value' => 'setting',
            'raw' => 0,
            'debug' => 0,
            'weight' => '3',
          ),
          'attack' => array(
            'name' => 'attack',
            'value' => 'stats/attack',
            'raw' => 0,
            'debug' => 0,
            'weight' => '4',
          ),
          'hp' => array(
            'name' => 'hp',
            'value' => 'stats/hp',
            'raw' => 0,
            'debug' => 0,
            'weight' => '5',
          ),
          'armor' => array(
            'name' => 'armor',
            'value' => 'stats/armor',
            'raw' => 0,
            'debug' => 0,
            'weight' => '6',
          ),
          'features' => array(
            'name' => 'features',
            'value' => 'qualities',
            'raw' => 0,
            'debug' => 0,
            'weight' => '7',
          ),
          'description' => array(
            'name' => 'description',
            'value' => 'description',
            'raw' => 0,
            'debug' => 0,
            'weight' => '8',
          ),
          'instinct' => array(
            'name' => 'instinct',
            'value' => 'instinct',
            'raw' => 0,
            'debug' => 0,
            'weight' => '9',
          ),
          'moves' => array(
            'name' => 'moves',
            'value' => 'moves/move',
            'raw' => 0,
            'debug' => 1,
            'weight' => '10',
          ),
        ),
        'context' => array(
          'value' => 'monsters/monster',
        ),
        'display_errors' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'debug_mode' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'armor',
            'target' => 'field_armor',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'attack',
            'target' => 'field_attack',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'features',
            'target' => 'field_features',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'hp',
            'target' => 'field_hit_points',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'instinct',
            'target' => 'field_instinct',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'monster_tags',
            'target' => 'field_mtags',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'moves',
            'target' => 'field_moves',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => 1,
          ),
          9 => array(
            'source' => 'setting',
            'target' => 'field_setting',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'monster',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['monsters'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'settings';
  $feeds_importer->config = array(
    'name' => 'Settings',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'context' => array(
          'value' => 'settings/setting',
        ),
        'sources' => array(
          'p' => array(
            'name' => 'p',
            'value' => 'p',
            'raw' => 0,
            'debug' => 1,
            'weight' => '1',
          ),
          'h3' => array(
            'name' => 'h3',
            'value' => 'h3',
            'raw' => 0,
            'debug' => 1,
            'weight' => '2',
          ),
        ),
        'display_errors' => 1,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'use_tidy' => FALSE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'h3',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'p',
            'target' => 'description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'settings',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['settings'] = $feeds_importer;

  return $export;
}
