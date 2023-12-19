package com.zkrallah.z_fire.presentation.main

import android.util.Log
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.zkrallah.z_fire.domain.models.Gas
import com.zkrallah.z_fire.domain.models.Humidity
import com.zkrallah.z_fire.domain.models.State
import com.zkrallah.z_fire.domain.models.Temp
import com.zkrallah.z_fire.domain.usecase.GetGas
import com.zkrallah.z_fire.domain.usecase.GetHumidity
import com.zkrallah.z_fire.domain.usecase.GetState
import com.zkrallah.z_fire.domain.usecase.GetTemp
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import javax.inject.Inject

@HiltViewModel
class MainViewModel @Inject constructor(
    private val getTemp: GetTemp,
    private val getHumidity: GetHumidity,
    private val getGas: GetGas,
    private val getState: GetState
) : ViewModel() {

    private val _temp: MutableStateFlow<Temp?> = MutableStateFlow(null)
    val temp = _temp.asStateFlow()
    private val _humidity: MutableStateFlow<Humidity?> = MutableStateFlow(null)
    val humidity = _humidity.asStateFlow()
    private val _gas: MutableStateFlow<Gas?> = MutableStateFlow(null)
    val gas = _gas.asStateFlow()
    private val _state: MutableStateFlow<State?> = MutableStateFlow(null)
    val state = _state.asStateFlow()

    fun fetchTemp() {
        viewModelScope.launch {
            try {
                getTemp().collect { result ->
                    result?.let {
                        _temp.emit(it)
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "fetchTempData: ${e.message}")
            }
        }
    }

    fun fetchHumidity() {
        viewModelScope.launch {
            try {
                getHumidity().collect { result ->
                    result?.let {
                        _humidity.emit(it)
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "fetchHumidityData: ${e.message}")
            }
        }
    }

    fun fetchGas() {
        viewModelScope.launch {
            try {
                getGas().collect { result ->
                    result?.let {
                        _gas.emit(it)
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "fetchGasData: ${e.message}")
            }
        }
    }

    fun fetchState() {
        viewModelScope.launch {
            try {
                getState().collect { result ->
                    result?.let {
                        _state.emit(it)
                    }
                }
            } catch (e: Exception) {
                Log.e(TAG, "fetchStateData: ${e.message}")
            }
        }
    }

    companion object {
        const val TAG = "MainViewModel"
    }

}