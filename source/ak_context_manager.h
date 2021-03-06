/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2017 - 2018 by Axel Kenzo, axelkenzo@mail.ru                                     */
/*                                                                                                 */
/*  Разрешается повторное распространение и использование как в виде исходного кода, так и         */
/*  в двоичной форме, с изменениями или без, при соблюдении следующих условий:                     */
/*                                                                                                 */
/*   1. При повторном распространении исходного кода должно оставаться указанное выше уведомление  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий.                   */
/*   2. При повторном распространении двоичного кода должна сохраняться указанная выше информация  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий в документации     */
/*      и/или в других материалах, поставляемых при распространении.                               */
/*   3. Ни имя владельца авторских прав, ни имена его соратников не могут быть использованы в      */
/*      качестве рекламы или средства продвижения продуктов, основанных на этом ПО без             */
/*      предварительного письменного разрешения.                                                   */
/*                                                                                                 */
/*  ЭТА ПРОГРАММА ПРЕДОСТАВЛЕНА ВЛАДЕЛЬЦАМИ АВТОРСКИХ ПРАВ И/ИЛИ ДРУГИМИ СТОРОНАМИ "КАК ОНА ЕСТЬ"  */
/*  БЕЗ КАКОГО-ЛИБО ВИДА ГАРАНТИЙ, ВЫРАЖЕННЫХ ЯВНО ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ИМИ, ПОДРАЗУМЕВАЕМЫЕ ГАРАНТИИ КОММЕРЧЕСКОЙ ЦЕННОСТИ И ПРИГОДНОСТИ ДЛЯ КОНКРЕТНОЙ */
/*  ЦЕЛИ. НИ В КОЕМ СЛУЧАЕ НИ ОДИН ВЛАДЕЛЕЦ АВТОРСКИХ ПРАВ И НИ ОДНО ДРУГОЕ ЛИЦО, КОТОРОЕ МОЖЕТ    */
/*  ИЗМЕНЯТЬ И/ИЛИ ПОВТОРНО РАСПРОСТРАНЯТЬ ПРОГРАММУ, КАК БЫЛО СКАЗАНО ВЫШЕ, НЕ НЕСЁТ              */
/*  ОТВЕТСТВЕННОСТИ, ВКЛЮЧАЯ ЛЮБЫЕ ОБЩИЕ, СЛУЧАЙНЫЕ, СПЕЦИАЛЬНЫЕ ИЛИ ПОСЛЕДОВАВШИЕ УБЫТКИ,         */
/*  ВСЛЕДСТВИЕ ИСПОЛЬЗОВАНИЯ ИЛИ НЕВОЗМОЖНОСТИ ИСПОЛЬЗОВАНИЯ ПРОГРАММЫ (ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ПОТЕРЕЙ ДАННЫХ, ИЛИ ДАННЫМИ, СТАВШИМИ НЕПРАВИЛЬНЫМИ, ИЛИ ПОТЕРЯМИ ПРИНЕСЕННЫМИ   */
/*  ИЗ-ЗА ВАС ИЛИ ТРЕТЬИХ ЛИЦ, ИЛИ ОТКАЗОМ ПРОГРАММЫ РАБОТАТЬ СОВМЕСТНО С ДРУГИМИ ПРОГРАММАМИ),    */
/*  ДАЖЕ ЕСЛИ ТАКОЙ ВЛАДЕЛЕЦ ИЛИ ДРУГОЕ ЛИЦО БЫЛИ ИЗВЕЩЕНЫ О ВОЗМОЖНОСТИ ТАКИХ УБЫТКОВ.            */
/*                                                                                                 */
/*   ak_context_manager.h                                                                          */
/* ----------------------------------------------------------------------------------------------- */
#ifndef __AK_CONTEXT_MANAGER_H__
#define __AK_CONTEXT_MANAGER_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <ak_buffer.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Класс состояний контекста. */
 typedef enum {
  /*! \brief контект не определен */
   node_undefined,
  /*! \brief контекст совпадает с хранимым вариантом (только создан/считан/записан) */
   node_is_equal,
  /*! \brief контекст изменен в процессе работы */
   node_modified
} ak_context_node_status;

/* ----------------------------------------------------------------------------------------------- */
 struct context_node;
/*! \brief Указатель на элемент структуры управления контекстами. */
 typedef struct context_node *ak_context_node;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Элемент структуры, предназначенной для управления контекстами. */
 struct context_node {
  /*! \brief указатель на контекст */
   ak_pointer ctx;
  /*! \brief дескриптор контекста */
   ak_handle id;
  /*! \brief тип контекста */
   ak_oid_engine engine;
  /*! \brief пользовательское описание */
   struct buffer description;
  /*! \brief статус контекста */
   ak_context_node_status status;
  /*! \brief функция удаления и очистки памяти из под контекста */
   ak_function_free_object *free;
};

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Создание нового элемента структуры управления контекстами. */
 ak_context_node ak_context_node_new( ak_pointer , ak_handle , ak_oid_engine ,
                                                         const char * , ak_function_free_object * );
/*! \brief Уничтожение элемента структуры управления контекстами. */
 ak_pointer ak_context_node_delete( ak_pointer );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Структура, предназначенная для управления контекстами. */
/*! Структура реализует массив указателей на произвольные контексты библиотеки, для которых
    определено действие delete (функция освобождения памяти, также см. \ref names).
    Данный массив предназначен, в первую очередь, для хранения указателей на ключевые контексты.
    Однако библиотекой в массив могут помещаться контексты, создаваемые динамически в ходе работы,
    например,
     - контексты функций хеширования,
     - буффер, содержащий узлы замены алгоритма блочного шифрования ГОСТ 28147-89,
     - буффер с параметрами эллиптической кривой,
     - структура, используемая для вычисления сжимающего отображения и т.п.

    При инициализации библиотеки создается один объект данного типа, который используется
    для работы с контекстами пользователя.
    Доступ пользователям библиотеки к данной структуре хранения данных закрыт.                     */
/* ----------------------------------------------------------------------------------------------- */
 struct context_manager {
  /*! \brief массив указателей на структуры управления контекстами */
   ak_context_node *array;
  /*! \brief общее количество выделенной по структуры управления памяти */
   size_t size;
  /*! \brief генератор, используемый для выработки ключей */
   struct random key_generator;
};

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Указатель на структуру управления ключами. */
 typedef struct context_manager *ak_context_manager;

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Инициализация структуры управления контекстами. */
 int ak_context_manager_create( ak_context_manager );
/*! \brief Уничтожение структуры управления контекстами. */
 int ak_context_manager_destroy( ak_context_manager );
/*! \brief Увеличение памяти для структуры управления контекстами. */
 int ak_context_manager_morealloc( ak_context_manager );
/*! \brief Добавление контекста в структуру управления контекстами. */
 ak_handle ak_context_manager_add_node( ak_context_manager , ak_pointer , ak_oid_engine ,
                                                        const char * , ak_function_free_object * );
/*! \brief Удаление контекста из структуры управления контекстами. */
 int ak_context_manager_delete_node( ak_context_manager , ak_handle );
/*! \brief Получение точного значения дескриптора по индексу массива. */
 ak_handle ak_context_manager_idx_to_handle( ak_context_manager , size_t );
/*! \brief Получение точного значения индекса массива по значению декскриптора. */
 size_t ak_context_manager_handle_to_idx( ak_context_manager , ak_handle );
/*! \brief Проверка корректности дескриптора контекста. */
 int ak_context_manager_handle_check( ak_context_manager , ak_handle , size_t * );

/*! \brief Инициализация глобальной структуры управления контекстами. */
 int ak_libakrypt_create_context_manager( void );
/*! \brief Удаление глобальной структуры управления контекстами. */
 int ak_libakrypt_destroy_context_manager( void );

/*! \brief Получение указателя на глобальную структуру управления контекстами. */
 ak_context_manager ak_libakrypt_get_context_manager( void );
/*! \brief Помещение созданного объекта в глоюальную структуру управления контекстами. */
 ak_handle ak_libakrypt_new_handle( ak_pointer , ak_oid_engine , const char * ,
                                                                        ak_function_free_object * );
/*! \brief Получение контекста по заданному дескриптору и типу контекста. */
 ak_pointer ak_handle_get_context( ak_handle, ak_oid_engine );

#endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                           ak_context_manager.h  */
/* ----------------------------------------------------------------------------------------------- */
