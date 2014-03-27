pbmid <clear.sql
bcp TRANS_DEF in ./data/trans_def.out -Umiduser -Pmiduser -c -t~
bcp TRANS_STEPS_DEF in ./data/trans_steps_def.out -Umiduser -Pmiduser -c -t~
bcp TRANS_VIEW_DEF in ./data/trans_view_def.out -Umiduser -Pmiduser -c -t~
