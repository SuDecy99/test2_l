#include "_text.h"

/**
 * Добавляет одну строку к тексту после строки с указанным номером
 * @param txt текст
 * @param line_number номер после которого нажо вставить строку
 * @param to_add текст новой строки
 * @returns статус
 */
int add_line_after(const text txt, int line_number, string to_add)
{
    list<string>::iterator it = txt->lines->begin();
    advance(it, line_number + 1);
    txt->lines->insert(it, to_add);

    return SUCCESS;
}
