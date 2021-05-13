//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Base.hpp"

namespace h3
{
	template<typename T> struct H3NetworkData;
#ifdef _H3API_TEMPLATE_DECLARE_
	template<typename _Elem>
	using NetworkData = H3NetworkData<_Elem>;
#endif /*_H3API_TEMPLATE_DECLARE_*/

	struct H3String;
	_H3API_DECLARE_(Network);

#pragma pack(push, 4)

	/** @brief Houses functionality related to multipleplay*/
	struct H3Network
	{
		/** @brief Checks if the current game features more than 1 human*/
		_H3API_ static BOOL8 Multiplayer();
		/**
		 * @brief Send up to 127 characters of text
		 * @param text Message to be sent
		 * @param player_id Destination player
		 */
		_H3API_ static VOID SendMessageToPlayer(LPCSTR text, INT32 player_id);
		/**
		 * @brief Send up to 127 characters of text
		 * @param text Message to be sent
		 * @param player_id Destination player
		 */
		_H3API_ static VOID SendMessageToPlayer(const H3String& text, INT32 player_id);
	};

	/** @brief Send data in between players*/
	template<typename T>
	struct H3NetworkData
	{
		/** @brief [00] -1 means everyone*/
		INT32   recipientId;
		h3unk32 _f_04;
		/** @brief [08] identifier for receiver to know how to handle data*/
		INT     msgId;
		/** @brief [0C] sizeof(*this) + extra size of H3NetworkData*/
		INT     bufferSize;
		INT     _f_10;
		/**
		 * @brief [14] All network messages are typenamed
		 */
		T data;
		/**
		 * @brief
		 * @tparam T
		 * @param recipient_id
		 * @param msg_id
		 * @param data
		 */
		_H3API_ H3NetworkData(INT32 recipient_id, INT32 msg_id, const T& data);

		/**
		 * @brief Send general data to another player
		 * @param compress_data Whether the data should be compressed before sending it over
		 * @param size You can specify whether you want to send fewer bytes than the full size, -1 sends full size
		 */
		_H3API_ VOID SendData(BOOL compress_data, INT32 size = -1);
	};

#pragma pack(pop) /* align-4 */

	template<typename T>
	_H3API_ H3NetworkData<T>::H3NetworkData(INT32 recipient_id, INT32 msg_id, const T& data) :
		recipientId(recipient_id), _f_04(), msgId(msg_id), bufferSize(0x14 + sizeof(T)), _f_10(), data(data)
	{
	}

	template<typename T>
	_H3API_ VOID h3::H3NetworkData<T>::SendData(BOOL compress_data, INT32 size /*= -1*/)
	{
		if (size != -1)
			bufferSize = size;
		return FASTCALL_4(INT32, 0x5549E0, this, 127, compress_data, 1);
	}

} /* namespace h3 */
