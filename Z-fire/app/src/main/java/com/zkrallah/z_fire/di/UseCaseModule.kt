package com.zkrallah.z_fire.di

import com.zkrallah.z_fire.domain.repositories.MainRepository
import com.zkrallah.z_fire.domain.usecase.GetGas
import com.zkrallah.z_fire.domain.usecase.GetHumidity
import com.zkrallah.z_fire.domain.usecase.GetState
import com.zkrallah.z_fire.domain.usecase.GetTemp
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import javax.inject.Singleton

@Module
@InstallIn(SingletonComponent::class)
object UseCaseModule {

    @Provides
    @Singleton
    fun provideGetTemp(
        mainRepository: MainRepository
    ): GetTemp {
        return GetTemp(mainRepository)
    }

    @Provides
    @Singleton
    fun provideGetHumidity(
        mainRepository: MainRepository
    ): GetHumidity {
        return GetHumidity(mainRepository)
    }

    @Provides
    @Singleton
    fun provideGetGas(
        mainRepository: MainRepository
    ): GetGas {
        return GetGas(mainRepository)
    }

    @Provides
    @Singleton
    fun provideGetState(
        mainRepository: MainRepository
    ): GetState {
        return GetState(mainRepository)
    }
}