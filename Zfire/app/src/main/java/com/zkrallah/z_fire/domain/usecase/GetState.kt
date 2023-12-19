package com.zkrallah.z_fire.domain.usecase

import com.zkrallah.z_fire.domain.repositories.MainRepository

class GetState(private val mainRepository: MainRepository) {
    suspend operator fun invoke() =  mainRepository.fetchState()
}