/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2008 - 2017 by Axel Kenzo, axelkenzo@mail.ru                                     */
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
/*   ak_magma.c                                                                                    */
/* ----------------------------------------------------------------------------------------------- */
 #include <ak_bckey.h>
 #include <ak_tools.h>
 #include <ak_context_manager.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Развернутые перестановки из ГОСТ Р 34.12-2015 для алгоритма Магма */
 const magma magma_boxes = {
  {
        108, 100, 102,  98, 106, 101, 107, 105, 110, 104, 109, 103,  96,  99, 111,  97,
        140, 132, 134, 130, 138, 133, 139, 137, 142, 136, 141, 135, 128, 131, 143, 129,
        44,  36,  38,  34,   42,  37,  43,  41,  46,  40,  45,  39,  32,  35,  47,  33,
        60,  52,  54,  50,  58,  53,   59,  57,  62,  56,  61,  55,  48,  51,  63,  49,
        156, 148, 150, 146, 154, 149, 155, 153, 158, 152, 157, 151, 144, 147, 159, 145,
        172, 164, 166, 162, 170, 165, 171, 169, 174, 168, 173, 167, 160, 163, 175, 161,
         92,  84,  86,  82,  90,  85,  91,  89,  94,  88,  93,  87,  80,  83,  95,  81,
        204, 196, 198, 194, 202, 197, 203, 201, 206, 200, 205, 199, 192, 195, 207, 193,
         28,  20,  22,  18,  26,  21,  27,  25,  30,  24,  29,  23,  16,  19,  31,  17,
        236, 228, 230, 226, 234, 229, 235, 233, 238, 232, 237, 231, 224, 227, 239, 225,
         76,  68,  70,  66,  74,  69,  75,  73,  78,  72,  77,  71,  64,  67,  79,  65,
        124, 116, 118, 114, 122, 117, 123, 121, 126, 120, 125, 119, 112, 115, 127, 113,
        188, 180, 182, 178, 186, 181, 187, 185, 190, 184, 189, 183, 176, 179, 191, 177,
        220, 212, 214, 210, 218, 213, 219, 217, 222, 216, 221, 215, 208, 211, 223, 209,
         12,   4,   6,   2,  10,   5,  11,   9,  14,   8,  13,   7,   0,   3,  15,   1,
        252, 244, 246, 242, 250, 245, 251, 249, 254, 248, 253, 247, 240, 243, 255, 241 },
  {
        203, 195, 197, 200, 194, 207, 202, 205, 206, 193, 199, 196, 204, 201, 198, 192,
        139, 131, 133, 136, 130, 143, 138, 141, 142, 129, 135, 132, 140, 137, 134, 128,
         43,  35,  37,  40,  34,  47,  42,  45,  46,  33,  39,  36,  44,  41,  38,  32,
         27,  19,  21,  24,  18,  31,  26,  29,  30,  17,  23,  20,  28,  25,  22,  16,
        219, 211, 213, 216, 210, 223, 218, 221, 222, 209, 215, 212, 220, 217, 214, 208,
         75,  67,  69,  72,  66,  79,  74,  77,  78,  65,  71,  68,  76,  73,  70,  64,
        251, 243, 245, 248, 242, 255, 250, 253, 254, 241, 247, 244, 252, 249, 246, 240,
        107,  99, 101, 104,  98, 111, 106, 109, 110,  97, 103, 100, 108, 105, 102,  96,
        123, 115, 117, 120, 114, 127, 122, 125, 126, 113, 119, 116, 124, 121, 118, 112,
         11,   3,   5,   8,   2,  15,  10,  13,  14,   1,   7,   4,  12,   9,   6,   0,
        171, 163, 165, 168, 162, 175, 170, 173, 174, 161, 167, 164, 172, 169, 166, 160,
         91,  83,  85,  88,  82,  95,  90,  93,  94,  81,  87,  84,  92,  89,  86,  80,
         59,  51,  53,  56,  50,  63,  58,  61,  62,  49,  55,  52,  60,  57,  54,  48,
        235, 227, 229, 232, 226, 239, 234, 237, 238, 225, 231, 228, 236, 233, 230, 224,
        155, 147, 149, 152, 146, 159, 154, 157, 158, 145, 151, 148, 156, 153, 150, 144,
        187, 179, 181, 184, 178, 191, 186, 189, 190, 177, 183, 180, 188, 185, 182, 176 },
  {
         87,  95,  85,  90,  88,  81,  86,  93,  80,  89,  83,  94,  91,  84,  82,  92,
        215, 223, 213, 218, 216, 209, 214, 221, 208, 217, 211, 222, 219, 212, 210, 220,
        247, 255, 245, 250, 248, 241, 246, 253, 240, 249, 243, 254, 251, 244, 242, 252,
        103, 111, 101, 106, 104,  97, 102, 109,  96, 105,  99, 110, 107, 100,  98, 108,
        151, 159, 149, 154, 152, 145, 150, 157, 144, 153, 147, 158, 155, 148, 146, 156,
         39,  47,  37,  42,  40,  33,  38,  45,  32,  41,  35,  46,  43,  36,  34,  44,
        199, 207, 197, 202, 200, 193, 198, 205, 192, 201, 195, 206, 203, 196, 194, 204,
        167, 175, 165, 170, 168, 161, 166, 173, 160, 169, 163, 174, 171, 164, 162, 172,
        183, 191, 181, 186, 184, 177, 182, 189, 176, 185, 179, 190, 187, 180, 178, 188,
        119, 127, 117, 122, 120, 113, 118, 125, 112, 121, 115, 126, 123, 116, 114, 124,
        135, 143, 133, 138, 136, 129, 134, 141, 128, 137, 131, 142, 139, 132, 130, 140,
         23,  31,  21,  26,  24,  17,  22,  29,  16,  25,  19,  30,  27,  20,  18,  28,
         71,  79,  69,  74,  72,  65,  70,  77,  64,  73,  67,  78,  75,  68,  66,  76,
         55,  63,  53,  58,  56,  49,  54,  61,  48,  57,  51,  62,  59,  52,  50,  60,
        231, 239, 229, 234, 232, 225, 230, 237, 224, 233, 227, 238, 235, 228, 226, 236,
          7,  15,   5,  10,   8,   1,   6,  13,   0,   9,   3,   14, 11,   4,   2,  12 },
  {
         24,  30,  18,  21,  22,  25,  17,  28,  31,  20,  27,  16,  29,  26,  19,  23,
        120, 126, 114, 117, 118, 121, 113, 124, 127, 116, 123, 112, 125, 122, 115, 119,
        232, 238, 226, 229, 230, 233, 225, 236, 239, 228, 235, 224, 237, 234, 227, 231,
        216, 222, 210, 213, 214, 217, 209, 220, 223, 212, 219, 208, 221, 218, 211, 215,
          8,  14,   2,   5,   6,   9,   1,  12,  15,   4,  11,   0,  13,  10,   3,   7,
         88,  94,  82,  85,  86,  89,  81,  92,  95,  84,  91,  80,  93,  90,  83,  87,
        136, 142, 130, 133, 134, 137, 129, 140, 143, 132, 139, 128, 141, 138, 131, 135,
         56,  62,  50,  53,  54,  57,  49,  60,  63,  52,  59,  48,  61,  58,  51,  55,
         72,  78,  66,  69,  70,  73,  65,  76,  79,  68,  75,  64,  77,  74,  67,  71,
        248, 254, 242, 245, 246, 249, 241, 252, 255, 244, 251, 240, 253, 250, 243, 247,
        168, 174, 162, 165, 166, 169, 161, 172, 175, 164, 171, 160, 173, 170, 163, 167,
        104, 110,  98, 101, 102, 105,  97, 108, 111, 100, 107,  96, 109, 106,  99, 103,
        152, 158, 146, 149, 150, 153, 145, 156, 159, 148, 155, 144, 157, 154, 147, 151,
        200, 206, 194, 197, 198, 201, 193, 204, 207, 196, 203, 192, 205, 202, 195, 199,
        184, 190, 178, 181, 182, 185, 177, 188, 191, 180, 187, 176, 189, 186, 179, 183,
         40,  46,  34,  37,  38,  41,  33,  44,  47,  36,  43,  32,  45,  42,  35,  39 }
 };

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Функция реализует один такт шифрующего преобразования ГОСТ 34.12-2015 (Mагма) */
 static ak_uint32 ak_magma_gostf( ak_uint32 x )
{
  x = magma_boxes[3][x>>24 & 255] << 24 | magma_boxes[2][x>>16 & 255] << 16 |
                                       magma_boxes[1][x>> 8 & 255] <<  8 | magma_boxes[0][x & 255];
  return x<<11 | x>>(32-11);
}

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Функция зашифрования одного блока информации алгоритмом ГОСТ 34.12-2015 (Магма) */
 static void ak_magma_encrypt_with_mask( ak_skey skey, ak_pointer in, ak_pointer out )
{
  ak_uint32 *kp = (ak_uint32 *) skey->key.data, *mp = (ak_uint32 *) skey->mask.data, p = 0;
  register ak_uint32 n1 = ((ak_uint32 *) in)[0];
  register ak_uint32 n2 = ((ak_uint32 *) in)[1];

  p = (n1 - mp[7]); p += kp[7]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[6]); p += kp[6]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[5]); p += kp[5]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[4]); p += kp[4]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[3]); p += kp[3]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[2]); p += kp[2]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[1]); p += kp[1]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[0]); p += kp[0]; n1 ^= ak_magma_gostf( p );

  p = (n1 - mp[7]); p += kp[7]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[6]); p += kp[6]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[5]); p += kp[5]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[4]); p += kp[4]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[3]); p += kp[3]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[2]); p += kp[2]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[1]); p += kp[1]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[0]); p += kp[0]; n1 ^= ak_magma_gostf( p );

  p = (n1 - mp[7]); p += kp[7]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[6]); p += kp[6]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[5]); p += kp[5]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[4]); p += kp[4]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[3]); p += kp[3]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[2]); p += kp[2]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[1]); p += kp[1]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[0]); p += kp[0]; n1 ^= ak_magma_gostf( p );

  p = (n1 - mp[0]); p += kp[0]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[1]); p += kp[1]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[2]); p += kp[2]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[3]); p += kp[3]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[4]); p += kp[4]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[5]); p += kp[5]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[6]); p += kp[6]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[7]); p += kp[7]; n1 ^= ak_magma_gostf( p );

 ((ak_uint32 *)out)[0] = n2; ((ak_uint32 *)out)[1] = n1;
}

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Функция расшифрования одного блока информации алгоритмом ГОСТ 34.12-2015 (Магма) */
 static void ak_magma_decrypt_with_mask( ak_skey skey, ak_pointer in, ak_pointer out )
{
  ak_uint32 *kp = (ak_uint32 *) skey->key.data, *mp = (ak_uint32 *) skey->mask.data, p = 0;
  register ak_uint32 n1 = ((ak_uint32 *) in)[0];
  register ak_uint32 n2 = ((ak_uint32 *) in)[1];

  p = (n1 - mp[7]); p += kp[7]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[6]); p += kp[6]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[5]); p += kp[5]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[4]); p += kp[4]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[3]); p += kp[3]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[2]); p += kp[2]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[1]); p += kp[1]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[0]); p += kp[0]; n1 ^= ak_magma_gostf( p );

  p = (n1 - mp[0]); p += kp[0]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[1]); p += kp[1]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[2]); p += kp[2]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[3]); p += kp[3]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[4]); p += kp[4]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[5]); p += kp[5]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[6]); p += kp[6]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[7]); p += kp[7]; n1 ^= ak_magma_gostf( p );

  p = (n1 - mp[0]); p += kp[0]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[1]); p += kp[1]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[2]); p += kp[2]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[3]); p += kp[3]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[4]); p += kp[4]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[5]); p += kp[5]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[6]); p += kp[6]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[7]); p += kp[7]; n1 ^= ak_magma_gostf( p );

  p = (n1 - mp[0]); p += kp[0]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[1]); p += kp[1]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[2]); p += kp[2]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[3]); p += kp[3]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[4]); p += kp[4]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[5]); p += kp[5]; n1 ^= ak_magma_gostf( p );
  p = (n1 - mp[6]); p += kp[6]; n2 ^= ak_magma_gostf( p );
  p = (n2 - mp[7]); p += kp[7]; n1 ^= ak_magma_gostf( p );

  ((ak_uint32 *)out)[0] = n2; ((ak_uint32 *)out)[1] = n1;
}

/* ----------------------------------------------------------------------------------------------- */
/*! Функция инициализируете контекст ключа блочного алгоритма шифрования Магма.
    После инициализации устанавливаются обработчики (функции класса). Однако само значение
    ключу не присваивается - поле `bkey->key` остается равным NULL.

    \b Внимание. Данная функция предназначена для использования другими функциями и не должна
    вызываться напрямую.

    @return Функция возвращает код ошибки. В случаее успеха возвращается \ref ak_error_ok.         */
/* ----------------------------------------------------------------------------------------------- */
 int ak_bckey_create_magma( ak_bckey bkey )
{
  int error = ak_error_ok;
  if( bkey == NULL ) return ak_error_message( ak_error_null_pointer, __func__,
                                                 "using null pointer to block cipher key context" );

 /* создаем ключ алгоритма шифрования и определяем его методы */
  if(( error = ak_bckey_create( bkey, 32, 8 )) != ak_error_ok )
    return ak_error_message( error, __func__, "wrong initalization of block cipher key context" );

 /* устанавливаем OID алгоритма шифрования */
  if(( bkey->key.oid =
         ak_handle_get_context( ak_oid_find_by_name( "magma" ), oid_engine )) == NULL ) {
    error = ak_error_get_value();
    ak_error_message( error, __func__, "wrong search of predefined magma block cipher OID" );
    ak_bckey_destroy( bkey );
    return error;
  };

 /* устанавливаем ресурс использования серетного ключа */
  bkey->key.resource.counter = ak_libakrypt_get_option( "magma_cipher_resource" );

 /* устанавливаем методы */
  bkey->key.data = NULL;
  bkey->key.set_mask = ak_skey_set_mask_additive;
  bkey->key.remask = ak_skey_remask_additive;
  bkey->key.set_icode = ak_skey_set_icode_additive;
  bkey->key.check_icode = ak_skey_check_icode_additive;

  bkey->schedule_keys = NULL;
  bkey->delete_keys = NULL;
  bkey->encrypt = ak_magma_encrypt_with_mask;
  bkey->decrypt = ak_magma_decrypt_with_mask;

 return error;
}

/* ----------------------------------------------------------------------------------------------- */
/*                                                                                     ak_magma.c  */
/* ----------------------------------------------------------------------------------------------- */
