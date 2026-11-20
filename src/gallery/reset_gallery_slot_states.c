extern unsigned short gallery_slot_0_state;
extern unsigned short gallery_slot_1_state;
extern unsigned short gallery_slot_2_state;
extern unsigned short gallery_slot_3_state;
extern unsigned short gallery_state_0;
extern unsigned short gallery_state_1;

void reset_gallery_slot_states(void)
{
    gallery_state_1 = 0;
    gallery_state_0 = 0;
    gallery_slot_3_state = 0;
    gallery_slot_2_state = 0;
    gallery_slot_1_state = 0;
    gallery_slot_0_state = 0;
}
