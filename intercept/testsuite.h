/** @file
 *    @brief MAVLink comm protocol testsuite generated from intercept.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef INTERCEPT_TESTSUITE_H
#define INTERCEPT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_intercept(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_development(system_id, component_id, last_msg);
    mavlink_test_intercept(system_id, component_id, last_msg);
}
#endif

#include "../development/testsuite.h"


static void mavlink_test_intercept(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_INTERCEPT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_intercept_t packet_in = {
        93372036854775807ULL,963497880,963498088,129.0,157.0,77,144
    };
    mavlink_intercept_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.intercept_lat = packet_in.intercept_lat;
        packet1.intercept_lon = packet_in.intercept_lon;
        packet1.intercept_alt = packet_in.intercept_alt;
        packet1.intercept_vel = packet_in.intercept_vel;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_INTERCEPT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_INTERCEPT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_intercept_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_intercept_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_intercept_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.time_usec , packet1.intercept_lat , packet1.intercept_lon , packet1.intercept_alt , packet1.intercept_vel );
    mavlink_msg_intercept_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_intercept_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.time_usec , packet1.intercept_lat , packet1.intercept_lon , packet1.intercept_alt , packet1.intercept_vel );
    mavlink_msg_intercept_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_intercept_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_intercept_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.time_usec , packet1.intercept_lat , packet1.intercept_lon , packet1.intercept_alt , packet1.intercept_vel );
    mavlink_msg_intercept_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("INTERCEPT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_INTERCEPT) != NULL);
#endif
}

static void mavlink_test_intercept(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_intercept(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // INTERCEPT_TESTSUITE_H
