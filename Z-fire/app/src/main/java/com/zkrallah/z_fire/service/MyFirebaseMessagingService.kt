package com.zkrallah.z_fire.service

import android.util.Log
import com.google.firebase.messaging.FirebaseMessagingService
import com.google.firebase.messaging.RemoteMessage

class MyFirebaseMessagingService : FirebaseMessagingService() {

    override fun onMessageReceived(message: RemoteMessage) {
        super.onMessageReceived(message)
        if (message.notification != null) {
            val title = message.notification?.title
            val body = message.notification?.body
            Log.d(TAG, "onMessageReceived: title:$title, body:$body")
        }

        if (message.data.isNotEmpty()) {
            Log.d(TAG, "onMessageReceived: false")
        }
    }

    override fun onNewToken(token: String) {
        super.onNewToken(token)
        Log.d(TAG, "onNewToken: $token")
    }

    companion object {
        const val TAG = "FirebaseCloudMessaging"
    }

}