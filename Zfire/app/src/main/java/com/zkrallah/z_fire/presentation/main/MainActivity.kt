package com.zkrallah.z_fire.presentation.main

import android.os.Bundle
import androidx.activity.viewModels
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.lifecycleScope
import com.zkrallah.z_fire.R
import com.zkrallah.z_fire.databinding.ActivityMainBinding
import dagger.hilt.android.AndroidEntryPoint
import kotlinx.coroutines.flow.collectLatest
import kotlinx.coroutines.launch

@AndroidEntryPoint
class MainActivity : AppCompatActivity() {

    private val binding: ActivityMainBinding by lazy {
        ActivityMainBinding.inflate(layoutInflater)
    }
    private val mainViewModel: MainViewModel by viewModels()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setObservers()
        fetchData()
        setContentView(binding.root)
    }

    private fun setObservers() {
        tempObserver()
        humidityObserver()
        gasObserver()
        stateObserver()
    }

    private fun fetchData() {
        fetchTemp()
        fetchHumidity()
        fetchGas()
        fetchState()
    }

    private fun fetchTemp(): Unit = mainViewModel.fetchTemp()
    private fun fetchHumidity(): Unit = mainViewModel.fetchHumidity()
    private fun fetchGas(): Unit = mainViewModel.fetchGas()
    private fun fetchState(): Unit = mainViewModel.fetchState()

    private fun tempObserver() {
        lifecycleScope.launch {
            mainViewModel.temp.collectLatest { response ->
                response?.let { data ->
                    binding.temp.text = getString(R.string.last_temp_c, data.value ?: "N/A")
                }
            }
        }
    }

    private fun humidityObserver() {
        lifecycleScope.launch {
            mainViewModel.humidity.collectLatest { response ->
                response?.let { data ->
                    binding.humidity.text = getString(R.string.last_humidity, data.value ?: "N/A")
                }
            }
        }
    }

    private fun gasObserver() {
        lifecycleScope.launch {
            mainViewModel.gas.collectLatest { response ->
                response?.let { data ->
                    binding.gas.text = getString(R.string.last_gas, data.value ?: "N/A")
                }
            }
        }
    }

    private fun stateObserver() {
        lifecycleScope.launch {
            mainViewModel.state.collectLatest { response ->
                response?.let { data ->
                    binding.state.text = getString(R.string.last_state, data.value ?: "N/A")
                }
            }
        }
    }

}