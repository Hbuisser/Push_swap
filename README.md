# push_swap

ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
ARG=`ruby -e "puts (-25..74).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG

python3 pyviz.py `ruby -e "puts (1..99).to_a.shuffle.join(' ')"`