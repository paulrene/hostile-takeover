#include "mixer.h"

namespace wi {

byte gabAdpcmSteppings[89][16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 255, 255, 255, 255, 254, 254,
    0, 1, 1, 2, 2, 3, 3, 4, 0, 255, 255, 254, 254, 253, 253, 252,
    0, 1, 1, 2, 2, 3, 3, 4, 0, 255, 255, 254, 254, 253, 253, 252,
    0, 1, 1, 2, 2, 3, 3, 4, 0, 255, 255, 254, 254, 253, 253, 252,
    0, 1, 1, 2, 2, 3, 3, 4, 0, 255, 255, 254, 254, 253, 253, 252,
    0, 1, 1, 2, 2, 3, 3, 4, 0, 255, 255, 254, 254, 253, 253, 252,
    0, 1, 2, 2, 3, 4, 5, 5, 0, 255, 254, 254, 253, 252, 251, 251,
    0, 1, 2, 2, 3, 4, 5, 5, 0, 255, 254, 254, 253, 252, 251, 251,
    0, 1, 2, 2, 3, 4, 5, 5, 0, 255, 254, 254, 253, 252, 251, 251,
    0, 1, 2, 2, 3, 4, 5, 5, 0, 255, 254, 254, 253, 252, 251, 251,
    1, 1, 2, 3, 4, 5, 6, 7, 255, 255, 254, 253, 252, 251, 250, 249,
    1, 1, 2, 3, 4, 5, 6, 7, 255, 255, 254, 253, 252, 251, 250, 249,
    1, 1, 3, 4, 5, 6, 8, 9, 255, 255, 253, 252, 251, 250, 248, 247,
    1, 1, 3, 4, 5, 6, 8, 9, 255, 255, 253, 252, 251, 250, 248, 247,
    1, 2, 3, 5, 6, 8, 9, 11, 255, 254, 253, 251, 250, 248, 247, 245,
    1, 2, 3, 5, 6, 8, 9, 11, 255, 254, 253, 251, 250, 248, 247, 245,
    1, 2, 4, 5, 7, 9, 11, 12, 255, 254, 252, 251, 249, 247, 245, 244,
    1, 2, 4, 5, 7, 9, 11, 12, 255, 254, 252, 251, 249, 247, 245, 244,
    1, 2, 4, 6, 8, 10, 12, 14, 255, 254, 252, 250, 248, 246, 244, 242,
    1, 2, 5, 7, 9, 11, 14, 16, 255, 254, 251, 249, 247, 245, 242, 240,
    1, 3, 5, 8, 10, 13, 15, 18, 255, 253, 251, 248, 246, 243, 241, 238,
    1, 3, 6, 8, 11, 14, 17, 19, 255, 253, 250, 248, 245, 242, 239, 237,
    2, 3, 6, 9, 12, 15, 18, 21, 254, 253, 250, 247, 244, 241, 238, 235,
    2, 3, 7, 10, 13, 16, 20, 23, 254, 253, 249, 246, 243, 240, 236, 233,
    2, 4, 8, 11, 15, 19, 23, 26, 254, 252, 248, 245, 241, 237, 233, 230,
    2, 4, 8, 12, 16, 20, 24, 28, 254, 252, 248, 244, 240, 236, 232, 228,
    2, 5, 9, 14, 18, 23, 27, 32, 254, 251, 247, 242, 238, 233, 229, 224,
    2, 5, 10, 14, 19, 24, 29, 33, 254, 251, 246, 242, 237, 232, 227, 223,
    3, 5, 11, 16, 21, 26, 32, 37, 253, 251, 245, 240, 235, 230, 224, 219,
    3, 6, 12, 18, 24, 30, 36, 42, 253, 250, 244, 238, 232, 226, 220, 214,
    3, 7, 13, 20, 26, 33, 39, 46, 253, 249, 243, 236, 230, 223, 217, 210,
    4, 7, 14, 21, 28, 35, 42, 49, 252, 249, 242, 235, 228, 221, 214, 207,
    4, 8, 16, 23, 31, 39, 47, 54, 252, 248, 240, 233, 225, 217, 209, 202,
    4, 9, 17, 26, 34, 43, 51, 60, 252, 247, 239, 230, 222, 213, 205, 196,
    5, 10, 19, 29, 38, 48, 57, 67, 251, 246, 237, 227, 218, 208, 199, 189,
    5, 11, 21, 32, 42, 53, 63, 74, 251, 245, 235, 224, 214, 203, 193, 182,
    6, 12, 23, 35, 46, 58, 69, 81, 250, 244, 233, 221, 210, 198, 187, 175,
    6, 13, 25, 38, 50, 63, 75, 88, 250, 243, 231, 218, 206, 193, 181, 168,
    7, 14, 28, 42, 56, 70, 84, 98, 249, 242, 228, 214, 200, 186, 172, 158,
    8, 15, 31, 46, 61, 76, 92, 107, 248, 241, 225, 210, 195, 180, 164, 149,
    8, 17, 34, 50, 67, 84, 101, 117, 248, 239, 222, 206, 189, 172, 155, 139,
    9, 19, 37, 56, 74, 93, 111, 130, 247, 237, 219, 200, 182, 163, 145, 126,
    10, 20, 41, 61, 81, 101, 122, 142, 246, 236, 215, 195, 175, 155, 134, 114,
    11, 22, 45, 67, 89, 111, 134, 156, 245, 234, 211, 189, 167, 145, 122, 100,
    12, 25, 49, 74, 98, 123, 147, 172, 244, 231, 207, 182, 158, 133, 109, 84,
    14, 27, 54, 81, 108, 135, 162, 189, 242, 229, 202, 175, 148, 121, 94, 67,
    15, 30, 60, 89, 119, 149, 179, 208, 241, 226, 196, 167, 137, 107, 77, 48,
    16, 33, 66, 98, 131, 164, 197, 229, 240, 223, 190, 158, 125, 92, 59, 27,
    18, 36, 72, 108, 144, 180, 216, 252, 238, 220, 184, 148, 112, 76, 40, 4,
    20, 40, 79, 119, 158, 198, 237, 255, 236, 216, 177, 137, 98, 58, 19, 1,
    22, 44, 87, 131, 174, 218, 255, 255, 234, 212, 169, 125, 82, 38, 1, 1,
    24, 48, 96, 144, 192, 240, 255, 255, 232, 208, 160, 112, 64, 16, 1, 1,
    26, 53, 106, 158, 211, 255, 255, 255, 230, 203, 150, 98, 45, 1, 1, 1,
    29, 58, 116, 174, 232, 255, 255, 255, 227, 198, 140, 82, 24, 1, 1, 1,
    32, 64, 128, 191, 255, 255, 255, 255, 224, 192, 128, 65, 1, 1, 1, 1,
};

char ganStepIndexMap[89][16] = {
    0, 0, 0, 0, 2, 4, 6, 8, 0, 0, 0, 0, 2, 4, 6, 8,
    0, 0, 0, 0, 3, 5, 7, 9, 0, 0, 0, 0, 3, 5, 7, 9,
    1, 1, 1, 1, 4, 6, 8, 10, 1, 1, 1, 1, 4, 6, 8, 10,
    2, 2, 2, 2, 5, 7, 9, 11, 2, 2, 2, 2, 5, 7, 9, 11,
    3, 3, 3, 3, 6, 8, 10, 12, 3, 3, 3, 3, 6, 8, 10, 12,
    4, 4, 4, 4, 7, 9, 11, 13, 4, 4, 4, 4, 7, 9, 11, 13,
    5, 5, 5, 5, 8, 10, 12, 14, 5, 5, 5, 5, 8, 10, 12, 14,
    6, 6, 6, 6, 9, 11, 13, 15, 6, 6, 6, 6, 9, 11, 13, 15,
    7, 7, 7, 7, 10, 12, 14, 16, 7, 7, 7, 7, 10, 12, 14, 16,
    8, 8, 8, 8, 11, 13, 15, 17, 8, 8, 8, 8, 11, 13, 15, 17,
    9, 9, 9, 9, 12, 14, 16, 18, 9, 9, 9, 9, 12, 14, 16, 18,
    10, 10, 10, 10, 13, 15, 17, 19, 10, 10, 10, 10, 13, 15, 17, 19,
    11, 11, 11, 11, 14, 16, 18, 20, 11, 11, 11, 11, 14, 16, 18, 20,
    12, 12, 12, 12, 15, 17, 19, 21, 12, 12, 12, 12, 15, 17, 19, 21,
    13, 13, 13, 13, 16, 18, 20, 22, 13, 13, 13, 13, 16, 18, 20, 22,
    14, 14, 14, 14, 17, 19, 21, 23, 14, 14, 14, 14, 17, 19, 21, 23,
    15, 15, 15, 15, 18, 20, 22, 24, 15, 15, 15, 15, 18, 20, 22, 24,
    16, 16, 16, 16, 19, 21, 23, 25, 16, 16, 16, 16, 19, 21, 23, 25,
    17, 17, 17, 17, 20, 22, 24, 26, 17, 17, 17, 17, 20, 22, 24, 26,
    18, 18, 18, 18, 21, 23, 25, 27, 18, 18, 18, 18, 21, 23, 25, 27,
    19, 19, 19, 19, 22, 24, 26, 28, 19, 19, 19, 19, 22, 24, 26, 28,
    20, 20, 20, 20, 23, 25, 27, 29, 20, 20, 20, 20, 23, 25, 27, 29,
    21, 21, 21, 21, 24, 26, 28, 30, 21, 21, 21, 21, 24, 26, 28, 30,
    22, 22, 22, 22, 25, 27, 29, 31, 22, 22, 22, 22, 25, 27, 29, 31,
    23, 23, 23, 23, 26, 28, 30, 32, 23, 23, 23, 23, 26, 28, 30, 32,
    24, 24, 24, 24, 27, 29, 31, 33, 24, 24, 24, 24, 27, 29, 31, 33,
    25, 25, 25, 25, 28, 30, 32, 34, 25, 25, 25, 25, 28, 30, 32, 34,
    26, 26, 26, 26, 29, 31, 33, 35, 26, 26, 26, 26, 29, 31, 33, 35,
    27, 27, 27, 27, 30, 32, 34, 36, 27, 27, 27, 27, 30, 32, 34, 36,
    28, 28, 28, 28, 31, 33, 35, 37, 28, 28, 28, 28, 31, 33, 35, 37,
    29, 29, 29, 29, 32, 34, 36, 38, 29, 29, 29, 29, 32, 34, 36, 38,
    30, 30, 30, 30, 33, 35, 37, 39, 30, 30, 30, 30, 33, 35, 37, 39,
    31, 31, 31, 31, 34, 36, 38, 40, 31, 31, 31, 31, 34, 36, 38, 40,
    32, 32, 32, 32, 35, 37, 39, 41, 32, 32, 32, 32, 35, 37, 39, 41,
    33, 33, 33, 33, 36, 38, 40, 42, 33, 33, 33, 33, 36, 38, 40, 42,
    34, 34, 34, 34, 37, 39, 41, 43, 34, 34, 34, 34, 37, 39, 41, 43,
    35, 35, 35, 35, 38, 40, 42, 44, 35, 35, 35, 35, 38, 40, 42, 44,
    36, 36, 36, 36, 39, 41, 43, 45, 36, 36, 36, 36, 39, 41, 43, 45,
    37, 37, 37, 37, 40, 42, 44, 46, 37, 37, 37, 37, 40, 42, 44, 46,
    38, 38, 38, 38, 41, 43, 45, 47, 38, 38, 38, 38, 41, 43, 45, 47,
    39, 39, 39, 39, 42, 44, 46, 48, 39, 39, 39, 39, 42, 44, 46, 48,
    40, 40, 40, 40, 43, 45, 47, 49, 40, 40, 40, 40, 43, 45, 47, 49,
    41, 41, 41, 41, 44, 46, 48, 50, 41, 41, 41, 41, 44, 46, 48, 50,
    42, 42, 42, 42, 45, 47, 49, 51, 42, 42, 42, 42, 45, 47, 49, 51,
    43, 43, 43, 43, 46, 48, 50, 52, 43, 43, 43, 43, 46, 48, 50, 52,
    44, 44, 44, 44, 47, 49, 51, 53, 44, 44, 44, 44, 47, 49, 51, 53,
    45, 45, 45, 45, 48, 50, 52, 54, 45, 45, 45, 45, 48, 50, 52, 54,
    46, 46, 46, 46, 49, 51, 53, 55, 46, 46, 46, 46, 49, 51, 53, 55,
    47, 47, 47, 47, 50, 52, 54, 56, 47, 47, 47, 47, 50, 52, 54, 56,
    48, 48, 48, 48, 51, 53, 55, 57, 48, 48, 48, 48, 51, 53, 55, 57,
    49, 49, 49, 49, 52, 54, 56, 58, 49, 49, 49, 49, 52, 54, 56, 58,
    50, 50, 50, 50, 53, 55, 57, 59, 50, 50, 50, 50, 53, 55, 57, 59,
    51, 51, 51, 51, 54, 56, 58, 60, 51, 51, 51, 51, 54, 56, 58, 60,
    52, 52, 52, 52, 55, 57, 59, 61, 52, 52, 52, 52, 55, 57, 59, 61,
    53, 53, 53, 53, 56, 58, 60, 62, 53, 53, 53, 53, 56, 58, 60, 62,
    54, 54, 54, 54, 57, 59, 61, 63, 54, 54, 54, 54, 57, 59, 61, 63,
    55, 55, 55, 55, 58, 60, 62, 64, 55, 55, 55, 55, 58, 60, 62, 64,
    56, 56, 56, 56, 59, 61, 63, 65, 56, 56, 56, 56, 59, 61, 63, 65,
    57, 57, 57, 57, 60, 62, 64, 66, 57, 57, 57, 57, 60, 62, 64, 66,
    58, 58, 58, 58, 61, 63, 65, 67, 58, 58, 58, 58, 61, 63, 65, 67,
    59, 59, 59, 59, 62, 64, 66, 68, 59, 59, 59, 59, 62, 64, 66, 68,
    60, 60, 60, 60, 63, 65, 67, 69, 60, 60, 60, 60, 63, 65, 67, 69,
    61, 61, 61, 61, 64, 66, 68, 70, 61, 61, 61, 61, 64, 66, 68, 70,
    62, 62, 62, 62, 65, 67, 69, 71, 62, 62, 62, 62, 65, 67, 69, 71,
    63, 63, 63, 63, 66, 68, 70, 72, 63, 63, 63, 63, 66, 68, 70, 72,
    64, 64, 64, 64, 67, 69, 71, 73, 64, 64, 64, 64, 67, 69, 71, 73,
    65, 65, 65, 65, 68, 70, 72, 74, 65, 65, 65, 65, 68, 70, 72, 74,
    66, 66, 66, 66, 69, 71, 73, 75, 66, 66, 66, 66, 69, 71, 73, 75,
    67, 67, 67, 67, 70, 72, 74, 76, 67, 67, 67, 67, 70, 72, 74, 76,
    68, 68, 68, 68, 71, 73, 75, 77, 68, 68, 68, 68, 71, 73, 75, 77,
    69, 69, 69, 69, 72, 74, 76, 78, 69, 69, 69, 69, 72, 74, 76, 78,
    70, 70, 70, 70, 73, 75, 77, 79, 70, 70, 70, 70, 73, 75, 77, 79,
    71, 71, 71, 71, 74, 76, 78, 80, 71, 71, 71, 71, 74, 76, 78, 80,
    72, 72, 72, 72, 75, 77, 79, 81, 72, 72, 72, 72, 75, 77, 79, 81,
    73, 73, 73, 73, 76, 78, 80, 82, 73, 73, 73, 73, 76, 78, 80, 82,
    74, 74, 74, 74, 77, 79, 81, 83, 74, 74, 74, 74, 77, 79, 81, 83,
    75, 75, 75, 75, 78, 80, 82, 84, 75, 75, 75, 75, 78, 80, 82, 84,
    76, 76, 76, 76, 79, 81, 83, 85, 76, 76, 76, 76, 79, 81, 83, 85,
    77, 77, 77, 77, 80, 82, 84, 86, 77, 77, 77, 77, 80, 82, 84, 86,
    78, 78, 78, 78, 81, 83, 85, 87, 78, 78, 78, 78, 81, 83, 85, 87,
    79, 79, 79, 79, 82, 84, 86, 88, 79, 79, 79, 79, 82, 84, 86, 88,
    80, 80, 80, 80, 83, 85, 87, 88, 80, 80, 80, 80, 83, 85, 87, 88,
    81, 81, 81, 81, 84, 86, 88, 88, 81, 81, 81, 81, 84, 86, 88, 88,
    82, 82, 82, 82, 85, 87, 88, 88, 82, 82, 82, 82, 85, 87, 88, 88,
    83, 83, 83, 83, 86, 88, 88, 88, 83, 83, 83, 83, 86, 88, 88, 88,
    84, 84, 84, 84, 87, 88, 88, 88, 84, 84, 84, 84, 87, 88, 88, 88,
    85, 85, 85, 85, 88, 88, 88, 88, 85, 85, 85, 85, 88, 88, 88, 88,
    86, 86, 86, 86, 88, 88, 88, 88, 86, 86, 86, 86, 88, 88, 88, 88,
    87, 87, 87, 87, 88, 88, 88, 88, 87, 87, 87, 87, 88, 88, 88, 88,
};

#if defined(__MWERKS__) && defined(__CPU_ARM)
// The stepping tables are globals. This declspec puts in a prologue which loads up r10 with
// the globals pointer and then restores it on exit. Could also do this by passing in the
// tables as parameters.
#pragma thumb off // below declspec only works in non-thumb mode
__declspec(pace_native_callback)
#endif
void MixChannels(Channel *achnl, int cchnl, byte *pb, word cb)
{
	byte *pbT = pb;
	while (pbT < &pb[cb]) {
		word cMixed = 0;
		word cSum1 = 0;
		word cSum2 = 0;

		for (int ichnl = 0; ichnl < cchnl; ichnl++) {
			Channel *pchnl = &achnl[ichnl];
			if (pchnl->pb < pchnl->pbEnd) {
				int nDelta = (*pchnl->pb) >> 4;
				pchnl->bSampleLast += gabAdpcmSteppings[pchnl->nStepIndex][nDelta];
				cSum1 += (word)pchnl->bSampleLast;
				pchnl->nStepIndex = ganStepIndexMap[pchnl->nStepIndex][nDelta];
				nDelta = (*pchnl->pb) & 0xf;
				pchnl->bSampleLast += gabAdpcmSteppings[pchnl->nStepIndex][nDelta];
				cSum2 += (word)pchnl->bSampleLast;
				pchnl->nStepIndex = ganStepIndexMap[pchnl->nStepIndex][nDelta];
				pchnl->pb++;
				cMixed++;
			}
		}
		if (cMixed == 0) {
			*pbT++ = 128;
			*pbT++ = 128;
		} else {
			*pbT++ = cSum1 / cMixed;
			*pbT++ = cSum2 / cMixed;
		}
	}
}
#if defined(__MWERKS__) && defined(__CPU_ARM)
#pragma thumb reset
#endif

} // namespace wi