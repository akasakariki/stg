//タイムラインスクリプト
<set_enemy_load,0,0>
<set_varble,0,flag>
<play_bgm,bgm/buraku.mp3>
<ravel,test>
<set_loadscript,2>
<set_enemy_wait,60>//3秒間待
<set_loadscript,2>
<set_enemy_wait,60>//3秒間待
<set_loadscript,2>
<set_enemy_wait,60>//3秒間待
<set_loadscript,2>
<set_enemy_wait,60>//3秒間待
<set_loadscript,2>
<set_enemy_wait,60>//3秒間待
<set_loadscript,2>
<set_enemy_wait,60>//3秒間待
<set_loadscript,2>
<ravel,tests>
<updata_varble,1,flag>
<goto_ravel,tests>//ループ
<if_goto_B,flag,=,1,tests>
<set_enemy_end>//処理の終わりを表し、ここでセットされたエネミーデーターを削除する
