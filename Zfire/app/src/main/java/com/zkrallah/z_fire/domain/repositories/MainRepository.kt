package com.zkrallah.z_fire.domain.repositories

import com.zkrallah.z_fire.domain.models.Gas
import com.zkrallah.z_fire.domain.models.Humidity
import com.zkrallah.z_fire.domain.models.State
import com.zkrallah.z_fire.domain.models.Temp
import kotlinx.coroutines.flow.StateFlow

interface MainRepository {
    suspend fun fetchTemp(): StateFlow<Temp?>
    suspend fun fetchHumidity(): StateFlow<Humidity?>
    suspend fun fetchGas(): StateFlow<Gas?>
    suspend fun fetchState(): StateFlow<State?>
}