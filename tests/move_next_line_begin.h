#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "common.h"
#include "text.h"
#include "_text.h"
}

TEST(mnlb, normal)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    move_next_line_begin(txt);

    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}

TEST(mnlb, last_line)
{
    text txt = create_text();
    txt->lines->push_back("line 0\n");
    txt->lines->push_back("line 1\n");
    txt->lines->push_back("line 2\n");
    txt->cursor->line_num = 2;
    txt->cursor->position = 0;

    move_next_line_begin(txt);

    EXPECT_EQ(txt->cursor->line_num, 2);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}

TEST(mnlb, empty_text)
{
    text txt = create_text();
    txt->cursor->line_num = -1; // при создании пустого текста
    txt->cursor->position = -1; // значения -1 -1

    move_next_line_begin(txt);

    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    free(txt);
}
