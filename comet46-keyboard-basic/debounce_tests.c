#include <stdint.h>
#include <stdio.h>

uint32_t remote_state = 0;

extern uint32_t debounce(uint32_t snapshot);

int does_not_fire_when_no_key_is_pressed()
{
	remote_state = 0;
	debounce(0);
	debounce(0);
	debounce(0);
	debounce(0);
	return debounce(0) == remote_state;
}

int does_not_fire_when_key_is_pressed_for_less_than_samples_count()
{
	remote_state = 0;
	debounce(1);
	debounce(1);
	debounce(0);
	debounce(1);
	return debounce(1) == remote_state;
}

int does_not_fire_when_key_is_released_for_less_than_samples_count()
{
	remote_state = 1;
	debounce(1);
	debounce(1);
	debounce(1);
	debounce(1);
	return debounce(0) == remote_state;
}

int fires_when_one_key_is_pressed_for_more_than_samples_count()
{
	remote_state = 0;
	debounce(1);
	debounce(1);
	debounce(1);
	debounce(1);
	return debounce(1) == 1;
}

int fires_when_only_one_key_is_pressed_for_more_than_samples_count()
{
	remote_state = 0;
	debounce(1);
	debounce(3);
	debounce(1);
	debounce(3);
	return debounce(1) == 1;
}

int fires_when_one_key_is_released_for_more_than_samples_count()
{
	remote_state = 3;
	debounce(2);
	debounce(2);
	debounce(2);
	debounce(2);
	return debounce(2) == 2;
}

void print_result(int result)
{
	fputs(result ? "true\n" : "false\n", stdout);
}

int run_tests()
{
	print_result(does_not_fire_when_no_key_is_pressed());
	print_result(does_not_fire_when_key_is_pressed_for_less_than_samples_count());
	print_result(does_not_fire_when_key_is_released_for_less_than_samples_count());
	print_result(fires_when_one_key_is_pressed_for_more_than_samples_count());
	print_result(fires_when_one_key_is_released_for_more_than_samples_count());
	print_result(fires_when_only_one_key_is_pressed_for_more_than_samples_count());
	getchar();
}