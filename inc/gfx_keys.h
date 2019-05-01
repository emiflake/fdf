/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_keys.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 00:56:56 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/01 19:53:55 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
** alphabetical key codes
*/
# define KC_A 0
# define KC_B 11
# define KC_C 8
# define KC_D 2
# define KC_E 14
# define KC_F 3
# define KC_G 5
# define KC_H 4
# define KC_I 34
# define KC_J 38
# define KC_K 40
# define KC_L 37
# define KC_M 46
# define KC_N 45
# define KC_O 31
# define KC_P 35
# define KC_R 15
# define KC_Q 12
# define KC_S 1
# define KC_T 17
# define KC_U 32
# define KC_V 9
# define KC_W 13
# define KC_X 7
# define KC_Y 16
# define KC_Z 6
/*
** number keys
*/
# define KC_1 18
# define KC_2 19
# define KC_3 20
# define KC_4 21
# define KC_5 22
# define KC_6 23
# define KC_7 24
# define KC_8 25
# define KC_9 26
# define KC_0 27

/*
** symbol keys
*/
# define KC_TILDE 50
# define KC_GRAVE 50
# define KC_BACKSLASH 42
# define KC_BKSLSH 42
# define KC_MINUS 27
# define KC_PLUS 24
# define KC_COMMA 43
# define KC_DOT 47
# define KC_SLASH 44

/*
** modifier keys
*/
# define KC_LSHIFT 257
# define KC_SHIFT 257
# define KC_RSHIFT 258
# define KC_LCTRL 256
# define KC_RCTRL 269
# define KC_CTRL 256
# define KC_LALT 261
# define KC_ALT 261
# define KC_RALT 262
# define KC_LSUPER 259
# define KC_RSUPER 260
# define KC_SUPER 259

/*
** special keys
*/
# define KC_ESC 53
# define KC_TAB 48
# define KC_CAPS 272
# define KC_RETURN 36
# define KC_ENTER 36
# define KC_FN 279
# define KC_DELETE 117
# define KC_DEL 117
# define KC_HOME 115
# define KC_END 119
# define KC_PAGEUP 116
# define KC_PAGEDOWN 121

/*
** arrow keys
*/
# define KC_UP 126
# define KC_DOWN 125
# define KC_LEFT 123
# define KC_RIGHT 124

# define KEY_LIMIT 512

typedef char	t_key_state[KEY_LIMIT];

void			gfx_key_state_down(t_key_state ks, int key_code);
void			gfx_key_state_up(t_key_state ks, int key_code);

void			gfx_debug_print_keystate(t_key_state keystate);

#endif
