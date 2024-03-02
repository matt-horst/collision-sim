#pragma once

#define ASSERT(_e, ...) { if  (!(_e)) { fprintf(stderr, __VA_ARGS__); exit(EXIT_FAILURE); }}

