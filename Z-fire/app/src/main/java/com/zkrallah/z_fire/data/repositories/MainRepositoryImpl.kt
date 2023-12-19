package com.zkrallah.z_fire.data.repositories

import android.util.Log
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import com.zkrallah.z_fire.domain.models.Gas
import com.zkrallah.z_fire.domain.models.Humidity
import com.zkrallah.z_fire.domain.models.State
import com.zkrallah.z_fire.domain.models.Temp
import com.zkrallah.z_fire.domain.repositories.MainRepository
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow

class MainRepositoryImpl(
    private val database: FirebaseDatabase
) : MainRepository {
    override suspend fun fetchTemp(): StateFlow<Temp?> {
        val response = MutableStateFlow<Temp?>(null)
        val reference = database.getReference("Data").child("Temp")

        reference.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                val tempModel = snapshot.getValue(Temp::class.java)
                response.value = tempModel
            }

            override fun onCancelled(error: DatabaseError) {
                Log.e(TAG, "onCancelled: ${error.message}")
            }

        })

        return response.asStateFlow()
    }

    override suspend fun fetchHumidity(): StateFlow<Humidity?> {
        val response = MutableStateFlow<Humidity?>(null)
        val reference = database.getReference("Data").child("Humidity")

        reference.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                val humidityModel = snapshot.getValue(Humidity::class.java)
                response.value = humidityModel
            }

            override fun onCancelled(error: DatabaseError) {
                Log.e(TAG, "onCancelled: ${error.message}")
            }

        })

        return response.asStateFlow()
    }

    override suspend fun fetchGas(): StateFlow<Gas?> {
        val response = MutableStateFlow<Gas?>(null)
        val reference = database.getReference("Data").child("Gas")

        reference.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                val gasModel = snapshot.getValue(Gas::class.java)
                response.value = gasModel
            }

            override fun onCancelled(error: DatabaseError) {
                Log.e(TAG, "onCancelled: ${error.message}")
            }

        })

        return response.asStateFlow()
    }

    override suspend fun fetchState(): StateFlow<State?> {
        val response = MutableStateFlow<State?>(null)
        val reference = database.getReference("Data").child("State")

        reference.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(snapshot: DataSnapshot) {
                val stateModel = snapshot.getValue(State::class.java)
                response.value = stateModel
            }

            override fun onCancelled(error: DatabaseError) {
                Log.e(TAG, "onCancelled: ${error.message}")
            }

        })

        return response.asStateFlow()
    }

    companion object {
        const val TAG = "MainRepositoryImpl"
    }
}