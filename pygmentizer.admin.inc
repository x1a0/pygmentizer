<?php

function pygmentizer_admin_page() {
  $form['pygmentizer_binary_path'] = array(
    '#title' => t('Pygment binary path'),
    '#description' => t('If you are using Linux, command "which pygmentize" could help you.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('pygmentizer_binary_path', '/usr/local/bin/pygmentize'),
  );

  $form['pygmentizer_style'] = array(
    '#title' => t('Style'),
    '#type' => 'select',
    '#options' => array(
      'monokai' => 'monokai',
      'manni' => 'manni',
      'perldoc' => 'perldoc',
      'borland' => 'borland',
      'colorful' => 'colorful',
      'default' => 'default',
      'murphy' => 'murphy',
      'vs' => 'vs',
      'trac' => 'trac',
      'tango' => 'tango',
      'fruity' => 'fruity',
      'autumn' => 'autumn',
      'bw' => 'bw',
      'emacs' => 'emacs',
      'vim' => 'vim',
      'pastie' => 'pastie',
      'friendly' => 'friendly',
      'native' => 'native',
      //'github' => 'github',
    ),
    '#default_value' => variable_get('pygmentizer_style', 'default'),
  );

  $preview_code = <<<PREVIEW
<pygmentize>
<?php
function example_form(&\$form_state, \$url) {

    // This is just a very simple form with one textfield, and a
    // submit button.
    \$form['example_text'] = array(
      '#type' => 'textfield',
      '#title' => st('Testing text'),
      '#default_value' => '',
      '#size' => 45,
      '#maxlength' => 45,
      '#required' => TRUE,
      '#description' => st('This is an example form demonstrating forms usage in the installer profiles tasks. Enter any text to see what happens.'),
    );

    \$form['continue'] = array(
      '#type' => 'submit',
      '#value' => st('Continue'),
    );

    // Note that #action is set to the url passed through from
    // installer, ensuring that it points to the same page, and
    // #redirect is FALSE to avoid broken installer workflow.
    \$form['errors'] = array();
    \$form['#action'] = \$url;
    \$form['#redirect'] = FALSE;

  return \$form;
}
?>
</pygmentize>
PREVIEW;

  $form['pygmentizer_style_preview'] = array(
    '#type' => 'item',
    '#title' => t('Theme preview'),
    '#markup' => _pygmentizer_inline_prepare($preview_code),
  );

  return system_settings_form($form, TRUE);
}
