#pragma once
// MESSAGE INTERCEPT PACKING

#define MAVLINK_MSG_ID_INTERCEPT 700


typedef struct __mavlink_intercept_t {
 uint64_t time_usec; /*< [us] Timestamp*/
 int32_t intercept_lat; /*< [degE7] Intercept latitude*/
 int32_t intercept_lon; /*< [degE7] Intercept longitude*/
 float intercept_alt; /*< [m] Intercept altitude AMSL*/
 float intercept_vel; /*< [m/s] Intercept velocity*/
 uint8_t target_system; /*<  Target system id*/
 uint8_t target_component; /*<  Target component id*/
} mavlink_intercept_t;

#define MAVLINK_MSG_ID_INTERCEPT_LEN 26
#define MAVLINK_MSG_ID_INTERCEPT_MIN_LEN 26
#define MAVLINK_MSG_ID_700_LEN 26
#define MAVLINK_MSG_ID_700_MIN_LEN 26

#define MAVLINK_MSG_ID_INTERCEPT_CRC 5
#define MAVLINK_MSG_ID_700_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_INTERCEPT { \
    700, \
    "INTERCEPT", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_intercept_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_intercept_t, target_component) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_intercept_t, time_usec) }, \
         { "intercept_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_intercept_t, intercept_lat) }, \
         { "intercept_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_intercept_t, intercept_lon) }, \
         { "intercept_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_intercept_t, intercept_alt) }, \
         { "intercept_vel", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_intercept_t, intercept_vel) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_INTERCEPT { \
    "INTERCEPT", \
    7, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_intercept_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_intercept_t, target_component) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_intercept_t, time_usec) }, \
         { "intercept_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_intercept_t, intercept_lat) }, \
         { "intercept_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_intercept_t, intercept_lon) }, \
         { "intercept_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_intercept_t, intercept_alt) }, \
         { "intercept_vel", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_intercept_t, intercept_vel) }, \
         } \
}
#endif

/**
 * @brief Pack a intercept message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Target system id
 * @param target_component  Target component id
 * @param time_usec [us] Timestamp
 * @param intercept_lat [degE7] Intercept latitude
 * @param intercept_lon [degE7] Intercept longitude
 * @param intercept_alt [m] Intercept altitude AMSL
 * @param intercept_vel [m/s] Intercept velocity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_intercept_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint64_t time_usec, int32_t intercept_lat, int32_t intercept_lon, float intercept_alt, float intercept_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INTERCEPT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, intercept_lat);
    _mav_put_int32_t(buf, 12, intercept_lon);
    _mav_put_float(buf, 16, intercept_alt);
    _mav_put_float(buf, 20, intercept_vel);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INTERCEPT_LEN);
#else
    mavlink_intercept_t packet;
    packet.time_usec = time_usec;
    packet.intercept_lat = intercept_lat;
    packet.intercept_lon = intercept_lon;
    packet.intercept_alt = intercept_alt;
    packet.intercept_vel = intercept_vel;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INTERCEPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INTERCEPT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
}

/**
 * @brief Pack a intercept message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  Target system id
 * @param target_component  Target component id
 * @param time_usec [us] Timestamp
 * @param intercept_lat [degE7] Intercept latitude
 * @param intercept_lon [degE7] Intercept longitude
 * @param intercept_alt [m] Intercept altitude AMSL
 * @param intercept_vel [m/s] Intercept velocity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_intercept_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint64_t time_usec, int32_t intercept_lat, int32_t intercept_lon, float intercept_alt, float intercept_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INTERCEPT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, intercept_lat);
    _mav_put_int32_t(buf, 12, intercept_lon);
    _mav_put_float(buf, 16, intercept_alt);
    _mav_put_float(buf, 20, intercept_vel);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INTERCEPT_LEN);
#else
    mavlink_intercept_t packet;
    packet.time_usec = time_usec;
    packet.intercept_lat = intercept_lat;
    packet.intercept_lon = intercept_lon;
    packet.intercept_alt = intercept_alt;
    packet.intercept_vel = intercept_vel;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INTERCEPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INTERCEPT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN);
#endif
}

/**
 * @brief Pack a intercept message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  Target system id
 * @param target_component  Target component id
 * @param time_usec [us] Timestamp
 * @param intercept_lat [degE7] Intercept latitude
 * @param intercept_lon [degE7] Intercept longitude
 * @param intercept_alt [m] Intercept altitude AMSL
 * @param intercept_vel [m/s] Intercept velocity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_intercept_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint64_t time_usec,int32_t intercept_lat,int32_t intercept_lon,float intercept_alt,float intercept_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INTERCEPT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, intercept_lat);
    _mav_put_int32_t(buf, 12, intercept_lon);
    _mav_put_float(buf, 16, intercept_alt);
    _mav_put_float(buf, 20, intercept_vel);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INTERCEPT_LEN);
#else
    mavlink_intercept_t packet;
    packet.time_usec = time_usec;
    packet.intercept_lat = intercept_lat;
    packet.intercept_lon = intercept_lon;
    packet.intercept_alt = intercept_alt;
    packet.intercept_vel = intercept_vel;
    packet.target_system = target_system;
    packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INTERCEPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INTERCEPT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
}

/**
 * @brief Encode a intercept struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param intercept C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_intercept_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_intercept_t* intercept)
{
    return mavlink_msg_intercept_pack(system_id, component_id, msg, intercept->target_system, intercept->target_component, intercept->time_usec, intercept->intercept_lat, intercept->intercept_lon, intercept->intercept_alt, intercept->intercept_vel);
}

/**
 * @brief Encode a intercept struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param intercept C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_intercept_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_intercept_t* intercept)
{
    return mavlink_msg_intercept_pack_chan(system_id, component_id, chan, msg, intercept->target_system, intercept->target_component, intercept->time_usec, intercept->intercept_lat, intercept->intercept_lon, intercept->intercept_alt, intercept->intercept_vel);
}

/**
 * @brief Encode a intercept struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param intercept C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_intercept_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_intercept_t* intercept)
{
    return mavlink_msg_intercept_pack_status(system_id, component_id, _status, msg,  intercept->target_system, intercept->target_component, intercept->time_usec, intercept->intercept_lat, intercept->intercept_lon, intercept->intercept_alt, intercept->intercept_vel);
}

/**
 * @brief Send a intercept message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  Target system id
 * @param target_component  Target component id
 * @param time_usec [us] Timestamp
 * @param intercept_lat [degE7] Intercept latitude
 * @param intercept_lon [degE7] Intercept longitude
 * @param intercept_alt [m] Intercept altitude AMSL
 * @param intercept_vel [m/s] Intercept velocity
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_intercept_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint64_t time_usec, int32_t intercept_lat, int32_t intercept_lon, float intercept_alt, float intercept_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INTERCEPT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, intercept_lat);
    _mav_put_int32_t(buf, 12, intercept_lon);
    _mav_put_float(buf, 16, intercept_alt);
    _mav_put_float(buf, 20, intercept_vel);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INTERCEPT, buf, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
#else
    mavlink_intercept_t packet;
    packet.time_usec = time_usec;
    packet.intercept_lat = intercept_lat;
    packet.intercept_lon = intercept_lon;
    packet.intercept_alt = intercept_alt;
    packet.intercept_vel = intercept_vel;
    packet.target_system = target_system;
    packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INTERCEPT, (const char *)&packet, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
#endif
}

/**
 * @brief Send a intercept message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_intercept_send_struct(mavlink_channel_t chan, const mavlink_intercept_t* intercept)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_intercept_send(chan, intercept->target_system, intercept->target_component, intercept->time_usec, intercept->intercept_lat, intercept->intercept_lon, intercept->intercept_alt, intercept->intercept_vel);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INTERCEPT, (const char *)intercept, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
#endif
}

#if MAVLINK_MSG_ID_INTERCEPT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_intercept_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint64_t time_usec, int32_t intercept_lat, int32_t intercept_lon, float intercept_alt, float intercept_vel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, intercept_lat);
    _mav_put_int32_t(buf, 12, intercept_lon);
    _mav_put_float(buf, 16, intercept_alt);
    _mav_put_float(buf, 20, intercept_vel);
    _mav_put_uint8_t(buf, 24, target_system);
    _mav_put_uint8_t(buf, 25, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INTERCEPT, buf, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
#else
    mavlink_intercept_t *packet = (mavlink_intercept_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->intercept_lat = intercept_lat;
    packet->intercept_lon = intercept_lon;
    packet->intercept_alt = intercept_alt;
    packet->intercept_vel = intercept_vel;
    packet->target_system = target_system;
    packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INTERCEPT, (const char *)packet, MAVLINK_MSG_ID_INTERCEPT_MIN_LEN, MAVLINK_MSG_ID_INTERCEPT_LEN, MAVLINK_MSG_ID_INTERCEPT_CRC);
#endif
}
#endif

#endif

// MESSAGE INTERCEPT UNPACKING


/**
 * @brief Get field target_system from intercept message
 *
 * @return  Target system id
 */
static inline uint8_t mavlink_msg_intercept_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field target_component from intercept message
 *
 * @return  Target component id
 */
static inline uint8_t mavlink_msg_intercept_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field time_usec from intercept message
 *
 * @return [us] Timestamp
 */
static inline uint64_t mavlink_msg_intercept_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field intercept_lat from intercept message
 *
 * @return [degE7] Intercept latitude
 */
static inline int32_t mavlink_msg_intercept_get_intercept_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field intercept_lon from intercept message
 *
 * @return [degE7] Intercept longitude
 */
static inline int32_t mavlink_msg_intercept_get_intercept_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field intercept_alt from intercept message
 *
 * @return [m] Intercept altitude AMSL
 */
static inline float mavlink_msg_intercept_get_intercept_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field intercept_vel from intercept message
 *
 * @return [m/s] Intercept velocity
 */
static inline float mavlink_msg_intercept_get_intercept_vel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a intercept message into a struct
 *
 * @param msg The message to decode
 * @param intercept C-struct to decode the message contents into
 */
static inline void mavlink_msg_intercept_decode(const mavlink_message_t* msg, mavlink_intercept_t* intercept)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    intercept->time_usec = mavlink_msg_intercept_get_time_usec(msg);
    intercept->intercept_lat = mavlink_msg_intercept_get_intercept_lat(msg);
    intercept->intercept_lon = mavlink_msg_intercept_get_intercept_lon(msg);
    intercept->intercept_alt = mavlink_msg_intercept_get_intercept_alt(msg);
    intercept->intercept_vel = mavlink_msg_intercept_get_intercept_vel(msg);
    intercept->target_system = mavlink_msg_intercept_get_target_system(msg);
    intercept->target_component = mavlink_msg_intercept_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_INTERCEPT_LEN? msg->len : MAVLINK_MSG_ID_INTERCEPT_LEN;
        memset(intercept, 0, MAVLINK_MSG_ID_INTERCEPT_LEN);
    memcpy(intercept, _MAV_PAYLOAD(msg), len);
#endif
}
