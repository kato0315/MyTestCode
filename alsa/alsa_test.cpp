#include <iostream>
#include <alsa/asoundlib.h>

int main()
{
    snd_ctl_t *ctl;
    snd_ctl_elem_list_t *list;
    snd_ctl_elem_info_t *elem_info;
    snd_ctl_elem_value_t *value;

    snd_ctl_open(&ctl, "hw:0", SND_CTL_NONBLOCK);
    snd_ctl_elem_list_malloc(&list);
    snd_ctl_elem_list_alloc_space(list, 100);
    snd_ctl_elem_list(ctl, list);

    snd_ctl_elem_info_malloc(&elem_info);
    snd_ctl_elem_value_malloc(&value);
    int numid = snd_ctl_elem_list_get_numid(list, 5);
   
//  int used = snd_ctl_elem_list_get_used(list);

 /*   
    for (int i = 0; i < used; i++) {
    	int numid = snd_ctl_elem_list_get_numid(list, i);
        std::cout << numid << std::endl;
        snd_ctl_elem_info_set_numid(elem_info, numid);
        snd_ctl_elem_info(ctl, elem_info);
        std::cout << "name:" << snd_ctl_elem_info_get_name(elem_info) << std::endl;
    }
*/

    snd_ctl_elem_info_set_numid(elem_info, numid);
    snd_ctl_elem_info(ctl, elem_info);

    snd_ctl_elem_value_set_numid(value, numid);
    snd_ctl_elem_read(ctl, value);

    std::cout << "name:" << snd_ctl_elem_info_get_name(elem_info) << std::endl;
    std::cout << snd_ctl_elem_info_get_min(elem_info) << std::endl;
    std::cout << snd_ctl_elem_info_get_max(elem_info) << std::endl;
    std::cout << snd_ctl_elem_value_get_integer(value, 0) << std::endl;

    return 0;
}
