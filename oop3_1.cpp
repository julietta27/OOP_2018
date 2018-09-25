Checking GIMP's Source Code with PVS-Studio
https://www.viva64.com/en/b/0273/

gint64 gimp_g_value_get_memsize (GValue *value)
{
  ....
  GimpArray *array = g_value_get_boxed (value);

  if (array)
    memsize += (sizeof (GimpArray) +
                array->static_data ? 0 : array->length);
  ....
}