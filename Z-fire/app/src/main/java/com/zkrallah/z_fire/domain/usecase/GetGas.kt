package com.zkrallah.z_fire.domain.usecase

import com.zkrallah.z_fire.domain.repositories.MainRepository


class GetGas(private val mainRepository: MainRepository) {
    suspend operator fun invoke() = mainRepository.fetchGas()
}
