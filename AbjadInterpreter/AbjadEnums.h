#pragma once

namespace AbjadTypes
{
//--------------------------------------------------------------------------------------------------

typedef enum
{
    t_invalid_token = 0,
    t_symbol,
    t_integer,
    t_literal,
    t_punctuation,
    t_keyword
} Tokens;

//--------------------------------------------------------------------------------------------------

typedef enum
{
    t_let = 0,
    t_for,
    t_to,
    t_step,
    t_next,
    t_dim,
    t_if,
    t_then,
    t_endif,
    t_read,
    t_data,
    t_end,
    t_function,
    t_return,
    t_program,
    t_input,
    t_print,
    t_int,
    t_left_dollar,
    t_right_dollar,
    t_chr,
    t_asc,
    t_procedure,
    t_end_procedure,
    t_randomise,
    t_rem,
    t_rnd

} Keywords;

//--------------------------------------------------------------------------------------------------
}