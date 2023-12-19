package com.zkrallah.z_fire.domain.usecase

import com.zkrallah.z_fire.domain.repositories.MainRepository

class GetHumidity(private val mainRepository: MainRepository) {
    suspend operator fun invoke() = mainRepository.fetchHumidity()
}